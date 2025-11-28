#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char sign[20];
    char color[20];
    int number;
    char advice[100];
} Forecast;

typedef struct {
    char name[50];
    Date dob;
    char sign[20];
} User;

void get_zodiac(int d, int m, char *sign) {
    if ((m == 3 && d >= 21) || (m == 4 && d <= 19)) strcpy(sign, "Aries");
    else if ((m == 4 && d >= 20) || (m == 5 && d <= 20)) strcpy(sign, "Taurus");
    else if ((m == 5 && d >= 21) || (m == 6 && d <= 20)) strcpy(sign, "Gemini");
    else if ((m == 6 && d >= 21) || (m == 7 && d <= 22)) strcpy(sign, "Cancer");
    else if ((m == 7 && d >= 23) || (m == 8 && d <= 22)) strcpy(sign, "Leo");
    else if ((m == 8 && d >= 23) || (m == 9 && d <= 22)) strcpy(sign, "Virgo");
    else if ((m == 9 && d >= 23) || (m == 10 && d <= 22)) strcpy(sign, "Libra");
    else if ((m == 10 && d >= 23) || (m == 11 && d <= 21)) strcpy(sign, "Scorpio");
    else if ((m == 11 && d >= 22) || (m == 12 && d <= 21)) strcpy(sign, "Sagittarius");
    else if ((m == 12 && d >= 22) || (m == 1 && d <= 19)) strcpy(sign, "Capricorn");
    else if ((m == 1 && d >= 20) || (m == 2 && d <= 18)) strcpy(sign, "Aquarius");
    else strcpy(sign, "Pisces");
}

void input_user(User *u) {
    printf("Enter Name: ");
    scanf(" %[^\n]s", u->name);
    printf("Enter Birth Date (DD MM YYYY): ");
    scanf("%d %d %d", &u->dob.day, &u->dob.month, &u->dob.year);
    get_zodiac(u->dob.day, u->dob.month, u->sign);
    printf("Assigned Zodiac: %s\n", u->sign);
}

void display_horoscope(User u, Forecast f[], int n) {
    int i;
    for(i=0; i<n; i++) {
        if(strcmp(u.sign, f[i].sign) == 0) {
            printf("\n--- Horoscope for %s ---\n", u.name);
            printf("Sign: %s\n", u.sign);
            printf("Lucky Color: %s\n", f[i].color);
            printf("Lucky Number: %d\n", f[i].number);
            printf("Advice: %s\n", f[i].advice);
            return;
        }
    }
}

void update_forecast(Forecast f[], int n) {
    char s[20];
    int i;
    printf("Enter Zodiac Sign to update: ");
    scanf("%s", s);
    for(i=0; i<n; i++) {
        if(strcmp(f[i].sign, s) == 0) {
            printf("Enter new Lucky Color: ");
            scanf("%s", f[i].color);
            printf("Enter new Lucky Number: ");
            scanf("%d", &f[i].number);
            printf("Enter new Advice: ");
            scanf(" %[^\n]s", f[i].advice);
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Sign not found.\n");
}

int main() {
    Forecast forecasts[12] = {
        {"Aries", "Red", 9, "Take action today."},
        {"Taurus", "Green", 6, "Be patient."},
        {"Gemini", "Yellow", 5, "Communicate clearly."},
        {"Cancer", "Silver", 2, "Trust your intuition."},
        {"Leo", "Gold", 1, "Lead with confidence."},
        {"Virgo", "Blue", 3, "Focus on details."},
        {"Libra", "Pink", 7, "Seek balance."},
        {"Scorpio", "Black", 8, "Embrace change."},
        {"Sagittarius", "Purple", 4, "Explore new ideas."},
        {"Capricorn", "Brown", 10, "Work hard."},
        {"Aquarius", "Cyan", 11, "Be innovative."},
        {"Pisces", "Sea Green", 12, "Dream big."}
    };

    User users[10];
    int user_count = 0;
    int choice;

    while(1) {
        printf("\n1. Add User\n2. Show Horoscope\n3. Update Forecast\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            input_user(&users[user_count]);
            user_count++;
        }
        else if(choice == 2) {
            char name[50];
            printf("Enter User Name: ");
            scanf(" %[^\n]s", name);
            int i, found=0;
            for(i=0; i<user_count; i++) {
                if(strcmp(users[i].name, name) == 0) {
                    display_horoscope(users[i], forecasts, 12);
                    found=1;
                    break;
                }
            }
            if(!found) printf("User not found.\n");
        }
        else if(choice == 3) {
            update_forecast(forecasts, 12);
        }
        else {
            break;
        }
    }
    return 0;
}
