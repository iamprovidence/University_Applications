package src;

public class ThreadProgram
{
    public static void main(String args[])
    {
        launch(new view.frames.ThreadFrame());
    }

    public static void launch(javax.swing.JFrame frame)
    {
        frame.setDefaultCloseOperation(javax.swing.JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
