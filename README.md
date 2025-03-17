# Customer Management and Electricity Cost System 

## Table of Contents
1. [Project Description](#project-description)
2. [Comparison of Exercise 1 and Exercise 2](#comparison-of-exercise-1-and-exercise-2)
3. [Installation Guide](#installation-guide)
4. [Usage Instructions](#usage-instructions)
   - [User Functions](#user-functions)
5. [Cost Calculation](#cost-calculation)
6. [Additional Information](#additional-information)

## Project Description
This project consists of two exercises related to **electricity management** using C programming:

1. **Exercise 1 - Electricity Cost Calculation**: Allows users to calculate their **electricity bill** based on energy consumption, house size, and days of usage.
2. **Exercise 2 - Customer Management System**: Manages multiple customers, allowing them to track and pay their monthly electricity bills.

## Comparison of Exercise 1 and Exercise 2
| Feature                | Exercise 1: Electricity Cost Calculation | Exercise 2: Customer Management System |
|------------------------|----------------------------------------|----------------------------------------|
| **User Registration**  | No                                     | Yes                                   |
| **Login System**       | Yes (Admin/User)                       | Yes (Customers)                       |
| **Cost Calculation**   | Based on single usage input            | Monthly cost tracking                 |
| **Payment System**     | One-time payment option               | Payment tracking per month            |
| **Admin Functionality**| Modify electricity rates              | Not available                         |
| **Most Expensive Bill**| No                                     | Yes                                   |

## Installation Guide
### Prerequisites
- **C Compiler** (GCC recommended)
- Compatible operating system (Linux, Windows, or macOS)

## Usage Instructions

### User Functions
#### Exercise 1: Electricity Cost Calculation
1. **SignUp & Login** (For Users and Admins)
2. **Calculate Cost** (One-time electricity usage calculation)
3. **Payment** (Card/Cash with discount for card payments)
4. **Admin Panel** (Modify energy rates)

#### Exercise 2: Customer Management System
1. **Register/Login** (Create and access user profiles)
2. **Modify Profile** (Edit address details)
3. **Calculate Monthly Costs** (For all 12 months)
4. **Payment System** (Track and pay for specific months)
5. **Most Expensive Month** (Find the highest paid month)

## Cost Calculation
The electricity cost is calculated as follows:
```plaintext
Final Charge = House Size * kWh Used * Energy Rate * (Days/365)
```
### Energy Rate Tiers
| kWh Range  | Rate (€/kWh) |
|------------|-------------|
| 0 - 1600   | 0.005 €     |
| 1601 - 2000| 0.008 €     |
| >2000      | 0.009 €     |

## Additional Information
- **Exercise 1** focuses on a **single-user electricity bill computation**.
- **Exercise 2** is a **multi-user system with monthly tracking**.
- Both programs use **console-based menus** for navigation.
