#include <stdio.h>

int userId[10], password[10];
int userCount = 0;

int busNo[3] = {101, 102, 103};
int seats[3] = {20, 25, 30};

int login = 0;
int bookedBus = 0;
int bookedSeat = 0;
int fare = 0;

int registerUser();
int userLogin();
int busDetails();
int bookTicket();
int cancelTicket();
int payment();
int receipt();

int main()
{
    int choice;

    do
    {
        printf("\n===== BUS RESERVATION SYSTEM =====\n");
        printf("1. Registration\n");
        printf("2. Login\n");
        printf("3. Bus Details\n");
        printf("4. Book Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. Payment\n");
        printf("7. Receipt\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: registerUser(); break;
            case 2: userLogin(); break;
            case 3: busDetails(); break;
            case 4: bookTicket(); break;
            case 5: cancelTicket(); break;
            case 6: payment(); break;
            case 7: receipt(); break;
            case 8: printf("Thank You\n"); break;
            default: printf("Wrong Choice\n");
        }

    } while(choice != 8);

    return 0;
}

int registerUser()
{
    if(userCount >= 10)
    {
        printf("User Limit Full\n");
        return 0;
    }

    printf("Enter User ID: ");
    scanf("%d", &userId[userCount]);

    printf("Enter Password: ");
    scanf("%d", &password[userCount]);

    userCount++;

    printf("Registration Successful\n");
    return 0;
}

int userLogin()
{
    int id, pass, i;

    if(userCount == 0)
    {
        printf("No User Registered\n");
        return 0;
    }

    printf("Enter User ID: ");
    scanf("%d", &id);

    printf("Enter Password: ");
    scanf("%d", &pass);

    for(i = 0; i < userCount; i++)
    {
        if(userId[i] == id && password[i] == pass)
        {
            login = 1;
            printf("Login Successful\n");
            return 0;
        }
    }

    printf("Invalid Login\n");
    return 0;
}

int busDetails()
{
    int i;

    printf("\n===== BUS DETAILS =====\n");

    for(i = 0; i < 3; i++)
    {
        printf("Bus Number: %d\n", busNo[i]);
        printf("Available Seats: %d\n\n", seats[i]);
    }

    return 0;
}

int bookTicket()
{
    int bus, seat;

    if(login == 0)
    {
        printf("Please Login First\n");
        return 0;
    }

    printf("Enter Bus Number: ");
    scanf("%d", &bus);

    printf("Enter Number of Seats: ");
    scanf("%d", &seat);

    if(seat <= 0)
    {
        printf("Invalid Seat Number\n");
        return 0;
    }

    if(bus == 101)
    {
        if(seats[0] >= seat)
        {
            seats[0] -= seat;
            bookedBus = bus;
            bookedSeat = seat;
            fare = seat * 500;
            printf("Booking Successful\n");
        }
        else
            printf("Seats Not Available\n");
    }
    else if(bus == 102)
    {
        if(seats[1] >= seat)
        {
            seats[1] -= seat;
            bookedBus = bus;
            bookedSeat = seat;
            fare = seat * 500;
            printf("Booking Successful\n");
        }
        else
            printf("Seats Not Available\n");
    }
    else if(bus == 103)
    {
        if(seats[2] >= seat)
        {
            seats[2] -= seat;
            bookedBus = bus;
            bookedSeat = seat;
            fare = seat * 500;
            printf("Booking Successful\n");
        }
        else
            printf("Seats Not Available\n");
    }
    else
    {
        printf("Invalid Bus Number\n");
    }

    return 0;
}

int cancelTicket()
{
    if(bookedBus == 0)
    {
        printf("No Ticket Booked\n");
        return 0;
    }

    if(bookedBus == 101)
        seats[0] += bookedSeat;
    else if(bookedBus == 102)
        seats[1] += bookedSeat;
    else if(bookedBus == 103)
        seats[2] += bookedSeat;

    bookedBus = 0;
    bookedSeat = 0;
    fare = 0;

    printf("Ticket Cancelled\n");
    return 0;
}

int payment()
{
    if(fare == 0)
    {
        printf("No Booking Found\n");
        return 0;
    }

    printf("Total Fare = %d\n", fare);
    printf("Payment Successful\n");

    return 0;
}

int receipt()
{
    if(bookedBus == 0)
    {
        printf("No Booking Found\n");
        return 0;
    }

    printf("\n===== RECEIPT =====\n");
    printf("Bus Number: %d\n", bookedBus);
    printf("Seats Booked: %d\n", bookedSeat);
    printf("Fare: %d\n", fare);

    return 0;
}
