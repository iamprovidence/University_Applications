
# Overview

This page contains all functional requirements of this project. They describe how our system should work and behave, so these requirements are very important and must be implemented in full.

## The Employee Functional Requirements

| No. | Functional Requirement Description |
| ------ | ------ |
| 1 | The employee shall be able to see 'Register Order' and 'View Order List' panels. |
| 2 | The employee shall create order in 3 steps and every step requires the previous one to be filled. |
| 3 | The order step shall have description and phone fields. |
| 4 | The order step shall have Sender and Receiver location groups with required city and street fields. |
| 5 | The cargo step shall have minimum one item. |
| 6 | The cargo item shall have width, height and length number fields. |
| 7 | The employee shall add and remove the cargo item when creating order. |
| 8 | The third creating order step shall contain confirmation question with confirm button.|
| 9 | The system shall send sms with TTN number to inputted phone number in the first creating order step after confirmation in the third step. |
| 10 | The system shall display page with information that order has been successfully created. |
| 11 | The employee shall be able to see order list via 'View Order List' panel. |
| 12 | The employee shall see valid TTN number for each order.|
| 13 | The employee shall see each order status (New, Delivering, Delivered, Completed, Canceled).|
| 14 | The order status shall change when the employee change order current location, cancel the order or client complete the order. | 
| 15 | The employee shall be able to delete order from the system. |
| 16 | The employee shall be able to edit current order location (city and street) to new one. |
| 17 | The employee shall be able to cancel the order. |

## The Client Functional Requirements

| No. | Functional Requirement Description |
| ------ | ------ |
| 1 | The client shall get TTN number in sms. |
| 2 | The client shall be able to see 'View Order History' panel. |
| 3 | The client shall be able to see order timeline by TTN number got from sms. |
| 4 | The client shall be able to complete order if it has already delivered to him. |

