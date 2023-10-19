#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int score1;
    int score2;
    float average;
};

void calculateAverage(struct Student *student) {
    student->average = (student->score1 + student->score2) / 2.0;
}

int main() {
    FILE *inputFile, *outputFile;
    struct Student *students;
    int numStudents, i;

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.");
        return 1;
    }

    // Read the number of students from the file
    fscanf(inputFile, "%d", &numStudents);

    // Allocate memory for students
    students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Read student information from the file
    for (i = 0; i < numStudents; i++) {
        fscanf(inputFile, "%s %d %d", students[i].name, &students[i].score1, &students[i].score2);
        calculateAverage(&students[i]);
    }

    // Close the input file
    fclose(inputFile);

    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.");
        return 1;
    }

    // Write student information and average scores to the output file
    for (i = 0; i < numStudents; i++) {
        fprintf(outputFile, "Name: %s, Score 1: %d, Score 2: %d, Average: %.2f\n", students[i].name, students[i].score1, students[i].score2, students[i].average);
    }

    // Close the output file
    fclose(outputFile);

    // Free allocated memory
    free(students);

    return 0;
}
