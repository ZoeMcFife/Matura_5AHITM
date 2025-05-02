-- Drop and create the database
DROP DATABASE IF EXISTS mini_school;
CREATE DATABASE mini_school;
USE mini_school;

-- Create a class table (primary entity)
CREATE TABLE class (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL UNIQUE,
    room VARCHAR(10),
    teacher_name VARCHAR(64)
);

-- Create a student table (related entity)
CREATE TABLE student (
    id INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(32) NOT NULL,
    lastname VARCHAR(32) NOT NULL,
    class_id INT, -- Foreign key to class.id

    CONSTRAINT fk_class
        FOREIGN KEY (class_id)
        REFERENCES class(id)
        ON UPDATE CASCADE
        ON DELETE SET NULL
);




CREATE TABLE course (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(64) NOT NULL UNIQUE,
    description TEXT
);

-- Junction table for many-to-many: student <-> course
CREATE TABLE student_course (
    student_id INT,
    course_id INT,
    enrolled_on DATE DEFAULT CURRENT_DATE,
    
    PRIMARY KEY (student_id, course_id),

    CONSTRAINT fk_student
        FOREIGN KEY (student_id)
        REFERENCES student(id)
        ON DELETE CASCADE,

    CONSTRAINT fk_course
        FOREIGN KEY (course_id)
        REFERENCES course(id)
        ON DELETE CASCADE
);

-- Insert some courses
INSERT INTO course (name, description) VALUES
('Mathematics', 'Advanced mathematics for high school'),
('English', 'Literature and grammar'),
('Physics', 'Introductory physics'),
('IT Basics', 'Programming and systems');

-- Enroll students in courses
-- Assume the student IDs from earlier inserts
INSERT INTO student_course (student_id, course_id) VALUES
(1, 1), -- Max Mustermann takes Mathematics
(1, 2), -- Max also takes English
(2, 1), -- Anna takes Mathematics
(2, 4), -- Anna takes IT Basics
(3, 3), -- John takes Physics
(4, 1), -- Lisa takes Mathematics
(4, 2), -- Lisa takes English
(4, 3); -- Lisa takes Physics

-- Insert data into class
INSERT INTO class (name, room, teacher_name) VALUES
('1A', 'Room 101', 'Mr. Huber'),
('1B', 'Room 102', 'Ms. Gruber'),
('2A', 'Room 201', 'Mr. Steiner');

-- Insert students assigned to classes
INSERT INTO student (firstname, lastname, class_id) VALUES
('Max', 'Mustermann', 1),
('Anna', 'Schmidt', 2),
('John', 'Doe', 1),
('Lisa', 'Müller', 3),
('Max', 'Musterfrau', NULL); -- A student not assigned to any class

-- Optional: Check inserted data
SELECT s.firstname, s.lastname, c.name AS class_name
FROM student s
LEFT JOIN class c ON s.class_id = c.id;
