#include <stdio.h>

#define MAX_SUBJECTS 10



float calculateAverage(int marks[], int numSubjects) {
    int sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += marks[i];
    }
    return (float)sum / numSubjects;
}


const char* getRemarks(float average) {
    if (average >= 90) return "Excellent";
    else if (average >= 75) return "Very Good";
    else if (average >= 60) return "Good";
    else if (average >= 50) return "Satisfactory";
    else return "Needs Improvement";
}

int main() {
    char name[50], stream[50], section[10];
    int rollNo, numSubjects;
    int marks[MAX_SUBJECTS];
    char subjects[MAX_SUBJECTS][50];

   
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter Stream: ");
    fgets(stream, sizeof(stream), stdin);
    printf("Enter Section: ");
    fgets(section, sizeof(section), stdin);
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter number of subjects: ");
    scanf("%d", &numSubjects);

    if (numSubjects > MAX_SUBJECTS) {
        printf("Maximum number of subjects allowed is %d.\n", MAX_SUBJECTS);
        return 1;
    }

  
    for (int i = 0; i < numSubjects; i++) {
        printf("Enter subject %d name: ", i + 1);
        scanf("%s", subjects[i]);
        printf("Enter marks for %s: ", subjects[i]);
        scanf("%d", &marks[i]);
    }


    float average = calculateAverage(marks, numSubjects);
    const char* remarks = getRemarks(average);

  

    printf("\n-------------------- Report Card --------------------\n");
    printf("Name: %s", name);
    printf("Stream: %s", stream);
    printf("Section: %s", section);
    printf("Roll No: %d\n", rollNo);
    printf("---------------------------------------------------\n");
    printf("Subjects and Marks:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("%s: %d\n", subjects[i], marks[i]);
    }
    printf("---------------------------------------------------\n");
    printf("Average Marks: %.2f\n", average);
    printf("Remarks: %s\n", remarks);
    printf("---------------------------------------------------\n");

    return 0;
}
