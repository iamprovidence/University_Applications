using PostOffice.Domain.Entities;

namespace PostOffice.Domain.Specifications
{
	internal class CompletedOrderSpec
	{
		public bool IsSatisfied(Order order)
		{
			return order.Status == Enums.OrderStatus.Completed;
		}
	}
}
