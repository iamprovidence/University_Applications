using PostOffice.Domain.Enums;
using PostOffice.Domain.Events;
using System;

namespace PostOffice.Domain.Visitors
{
	internal class CalcOrderTimeVisitor
	{
		private DateTime _startTime;
		private DateTime _endTime;

		public void Visit(OrderCreatedDomainEvent orderCreatedDomainEvent)
		{
			StartCalc(orderCreatedDomainEvent.CreationDate);
		}

		public void Visit(OrderStatusChangedDomainEvent orderStatusChangedDomainEvent)
		{
			if (orderStatusChangedDomainEvent.Status == OrderStatus.Completed)
			{
				EndCalc(orderStatusChangedDomainEvent.CreationDate);
			}
		}

		public TimeSpan GetResult()
		{
			return _endTime - _startTime;
		}

		private void StartCalc(DateTime creationDate)
		{
			_startTime = creationDate;
		}

		private void EndCalc(DateTime creationDate)
		{
			_endTime = creationDate;
		}
	}
}
