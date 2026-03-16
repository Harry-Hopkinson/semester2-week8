#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#define NAME_LENGTH 50
#define NUM_MODULES 3

/**
 * Structure to represent a student
 */
struct student_record
{
    char name[NAME_LENGTH];   // Student's name
    int id;                   // Student's ID number
    float marks[NUM_MODULES]; // Marks for three modules
};

/*
 * function headers
 */
float calculate_average(struct student_record student);
void display_student(struct student_record student);

#endif // STUDENT_RECORD_H