namespace MemoryManagment
{
    class MemoryBlock
    {
        public int BlockIndex { get; private set; }
        public int Size { get; private set; }
        public bool IsLocked { get; private set; }

        public MemoryBlock(int blockIndex, int size)
            : this(blockIndex, size, false) { }

        public MemoryBlock(int blockIndex, int size, bool isLocked)
        {
            BlockIndex = blockIndex;
            Size = size;
            IsLocked = isLocked;
        }

        public int CalcSpace(MemoryBlock memoryBlock)
        {
            return BlockIndex - (memoryBlock.BlockIndex + memoryBlock.Size);
        }
    }

    class MemoryAllocator
    {
        private readonly LinkedList<MemoryBlock> _allocatedMemory;

        public MemoryAllocator(int size)
        {
            _allocatedMemory = new LinkedList<MemoryBlock>();

            _allocatedMemory.AddFirst(new LinkedListNode<MemoryBlock>(new MemoryBlock(0, 0, true)));
            _allocatedMemory.AddLast(new LinkedListNode<MemoryBlock>(new MemoryBlock(size, 0, true)));
        }

        public LinkedList<MemoryBlock> GetMemory()
        {
            return new LinkedList<MemoryBlock>(_allocatedMemory);
        }

        public int GetTotalSize()
        {
            return _allocatedMemory.Last!.Value.BlockIndex;
        }

        public int GetFreeSize()
        {
            return GetTotalSize() - _allocatedMemory.Sum(x => x.Size);
        }

        public int? Allocate(int numberOfBlocksToAllocate)
        {
            var lastAllocatedBlock = TryGetLastAllocatedBlock(numberOfBlocksToAllocate);

            if (lastAllocatedBlock == null)
            {
                return null;
            }

            var newBlockIndex = lastAllocatedBlock.Value.BlockIndex + lastAllocatedBlock.Value.Size;
            var newBlock = new MemoryBlock(newBlockIndex, numberOfBlocksToAllocate);
            _allocatedMemory.AddAfter(lastAllocatedBlock, newBlock);

            return newBlockIndex;
        }

        private LinkedListNode<MemoryBlock>? TryGetLastAllocatedBlock(int numberOfBlocksToAllocate)
        {
            for (var memoryBlock = _allocatedMemory.First!; memoryBlock!.Next != null; memoryBlock = memoryBlock.Next)
            {
                var freeSpace = memoryBlock.Next.Value.CalcSpace(memoryBlock.Value);

                if (freeSpace >= numberOfBlocksToAllocate)
                {
                    return memoryBlock;
                }
            }

            return null;
        }

        public bool Free(int blockIndex)
        {
            var block = _allocatedMemory
                .Where(x => !x.IsLocked)
                .Where(x => x.BlockIndex == blockIndex)
                .SingleOrDefault();

            if (block == null)
            {
                return false;
            }

            _allocatedMemory.Remove(block);

            return true;
        }
    }

    static class MemoryAllocatorPresenter
    {
        public static void Print(MemoryAllocator allocator, int rowWidth)
        {
            Console.WriteLine($"Total size : {allocator.GetTotalSize()}");
            Console.WriteLine($"Free size : {allocator.GetFreeSize()}");

            var buffer = GetPrintBuffer(allocator);
            PrintBuffer(buffer, rowWidth);

            Console.WriteLine();
        }

        private static List<char> GetPrintBuffer(MemoryAllocator allocator)
        {
            var buffer = new List<char>();

            for (var block = allocator.GetMemory().First; block != null; block = block.Next)
            {
                var memoryBlockChars = RenderMemoryBlock(block.Value);
                buffer.AddRange(memoryBlockChars);

                var freeSpaceChards = RenderFreeSpace(block.Value, block.Next?.Value);
                buffer.AddRange(freeSpaceChards);
            }

            // trim last "|"
            if (buffer.Last() == '|')
            {
                buffer.RemoveAt(buffer.Count - 1);
            }

            return buffer;
        }

        private static char[] RenderMemoryBlock(MemoryBlock block)
        {
            if (block.IsLocked)
            {
                return [];
            }

            var blockDataToRender = new List<char>();
            blockDataToRender.AddRange(block.BlockIndex.ToString().ToCharArray());
            blockDataToRender.AddRange(new string('x', block.Size).ToCharArray());
            blockDataToRender.Add('|');

            return blockDataToRender.ToArray();
        }

        private static char[] RenderFreeSpace(MemoryBlock currentBlock, MemoryBlock? nextBlock)
        {
            if (nextBlock == null)
            {
                return [];
            }

            var freeSpace = nextBlock.CalcSpace(currentBlock);

            if (freeSpace <= 0)
            {
                return [];
            }

            var freeDataToRender = new List<char>();
            freeDataToRender.AddRange(new string(' ', freeSpace).ToCharArray());
            freeDataToRender.Add('|');

            return freeDataToRender.ToArray();
        }

        private static void PrintBuffer(List<char> buffer, int rowWidth)
        {
            var numberOfRows = (int)Math.Ceiling((decimal)buffer.Count / rowWidth);

            for (var rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
            {
                PrintRow(buffer, rowIndex, rowWidth);
                Console.WriteLine();
            }
        }

        private static void PrintRow(List<char> buffer, int rowIndex, int rowWidth)
        {
            Console.Write("|");

            var charOffset = rowIndex * rowWidth;
            for (var i = 0; i < rowWidth; i++)
            {
                var charIndex = i + charOffset;

                var isOutOfRange = charIndex >= buffer.Count;

                if (isOutOfRange) Console.Write(buffer.Last());
                else Console.Write(buffer[charIndex]);
            }

            Console.Write("|");
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            var memorySize = 30;
            var rowWidth = 10;

            var memoryAllocator = new MemoryAllocator(memorySize);

            var helpText =
                """
                allocate X - allocate X block of memory
                free X     - free X block of memory
                print      - print current memory state
                """;

            Console.WriteLine(helpText);
            Console.WriteLine();

            while (true)
            {
                var command = Console.ReadLine() ?? "";

                if (command.StartsWith("allocate"))
                {
                    ExecuteAllocateCommand(memoryAllocator, command);
                }
                else if (command.StartsWith("free"))
                {
                    ExecuteFreeCommand(memoryAllocator, command);
                }
                else if (command == "print")
                {
                    MemoryAllocatorPresenter.Print(memoryAllocator, rowWidth);
                }
                else
                {
                    WriteLine("Unknown command", ConsoleColor.Red);
                }
            }
        }

        private static void ExecuteAllocateCommand(MemoryAllocator memoryAllocator, string command)
        {
            int size;

            try
            {
                size = int.Parse(command.Split(" ").Last());
            }
            catch (Exception)
            {
                WriteLine($"Wrong command input", ConsoleColor.Red);
                return;
            }

            var allocatedBlockIndex = memoryAllocator.Allocate(size);

            if (!allocatedBlockIndex.HasValue)
            {
                WriteLine($"Not enough space", ConsoleColor.Red);
            }
            else
            {
                Console.WriteLine($"Allocated block index : {allocatedBlockIndex}");
            }
        }

        private static void ExecuteFreeCommand(MemoryAllocator memoryAllocator, string command)
        {
            int blockIndex;
            try
            {
                blockIndex = int.Parse(command.Split(" ").Last());
            }
            catch (Exception)
            {
                WriteLine($"Wrong command input", ConsoleColor.Red);
                return;
            }

            var isFreed = memoryAllocator.Free(blockIndex);

            if (isFreed)
            {
                Console.WriteLine("Memory freed");
            }
            else
            {
                WriteLine($"Memory not freed", ConsoleColor.Red);
            }
        }

        private static void WriteLine(string text, ConsoleColor consoleColor)
        {
            Console.ForegroundColor = consoleColor;
            Console.WriteLine(text);
            Console.ResetColor();
        }
    }
}
