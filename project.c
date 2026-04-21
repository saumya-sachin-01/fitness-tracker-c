#include <stdio.h>
#include <string.h>

int main() {
    printf("!! Welcome To Personal Health and Fitness Management System !!\n");
    printf("Create Your Profile\n");

    char name[50];
    int age;
    char gender;
    char goal[100];
    int choice;

    printf("Enter Your Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter Your Age: ");
    scanf("%d", &age);

    printf("Enter Your Gender (M/F): ");
    scanf(" %c", &gender);

    printf("\nProfile Created Successfully!!\n");
    printf("Your Profile Details:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);

    printf("\nThank you %s for using our system!!\n", name);

    FILE *fp;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Add Your Fitness Goal\n");
        printf("2. Record of Current Day\n");
        printf("3. Record of Previous Days\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter Your Fitness Goal: ");
            getchar();
            fgets(goal, sizeof(goal), stdin);
            printf("Fitness Goal Added Successfully!!\n");
            printf("Your Fitness Goal: %s\n", goal);
            break;

        case 2: {
            char ready;
            int sleephours = 0, wakeup_time = 0, meals = 0, water = 0;
            char exercise = 'N', food = 'N', food_type;

            printf("\nAre you ready to answer today's questions? (Y/N): ");
            scanf(" %c", &ready);

            if (ready == 'Y' || ready == 'y') {
                printf("How many hours did you sleep last night: ");
                scanf("%d", &sleephours);

                if (sleephours < 6)
                    printf("Try to get more sleep.\n");
                else if (sleephours > 8)
                    printf("Maintain a balanced routine.\n");
                else
                    printf("Good job!\n");

                printf("Enter wakeup hour (0-23): ");
                scanf("%d", &wakeup_time);

                if (wakeup_time < 6)
                    printf("Great! Early wake-up.\n");
                else
                    printf("Try waking up earlier.\n");

                printf("Did you exercise today (Y/N): ");
                scanf(" %c", &exercise);

                if (exercise == 'Y' || exercise == 'y') {
                    int rounds;
                    printf("How many rounds of exercise: ");
                    scanf("%d", &rounds);
                    printf("Good job! You did %d rounds.\n", rounds);
                } else {
                    printf("Try to exercise daily.\n");
                }

                printf("How many times did you eat today: ");
                scanf("%d", &meals);

                if (meals == 3)
                    printf("Good eating habit.\n");
                else if (meals < 3)
                    printf("Try to eat 3 meals daily.\n");
                else
                    printf("Avoid overeating.\n");

                printf("Food category (H for Homemade / O for Other): ");
                scanf(" %c", &food);

                if (food == 'H' || food == 'h') {
                    printf("Food type (L for Light / O for Other): ");
                    scanf(" %c", &food_type);
                    if (food_type == 'L' || food_type == 'l')
                        printf("Healthy choice!\n");
                    else
                        printf("Try light food.\n");
                } else {
                    printf("Try homemade food.\n");
                }

                printf("How many glasses of water did you drink today: ");
                scanf("%d", &water);

                if (water >= 8)
                    printf("Good hydration!\n");
                else
                    printf("Drink at least 8 glasses daily.\n");

                char save;
                printf("Do you want to save today's record? (Y/N): ");
                scanf(" %c", &save);

                if (save == 'Y' || save == 'y') {
                    fp = fopen("fitness_record.txt", "a");
                    if (fp == NULL) {
                        printf("Error opening file!\n");
                    
                    }

                    fprintf(fp, "Name: %s\n", name);
                    fprintf(fp, "Age: %d\n", age);
                    fprintf(fp, "Gender: %c\n", gender);
                    fprintf(fp, "Fitness Goal: %s", goal);
                    fprintf(fp, "Sleep Hours: %d\n", sleephours);
                    fprintf(fp, "Wakeup Time: %d\n", wakeup_time);
                    fprintf(fp, "Exercise: %c\n", exercise);
                    fprintf(fp, "Meals: %d\n", meals);
                    fprintf(fp, "Food Category: %c\n", food);
                    fprintf(fp, "Water Intake: %d glasses\n", water);
                    fprintf(fp, "-----------------------------\n");

                    fclose(fp);
                    printf("Today's record saved successfully!\n");
                } else {
                    printf("Record not saved.\n");
                }
            } else {
                printf("You can record your day later.\n");
            }
            break;
        }

        case 3: {
            char record[500];
            fp = fopen("fitness_record.txt", "r");

            if (fp == NULL) {
                printf("No previous records found.\n");
                break;
            }

            printf("\n--- Previous Records ---\n");
            while (fgets(record, sizeof(record), fp) != NULL) {
                printf("%s", record);
            }
            fclose(fp);
            break;
        }

        case 4:
            printf("Exiting the system. Stay healthy!\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}