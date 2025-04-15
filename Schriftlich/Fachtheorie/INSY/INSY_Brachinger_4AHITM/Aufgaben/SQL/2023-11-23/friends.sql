DROP DATABASE IF EXISTS friendDB;

CREATE DATABASE friendDB DEFAULT CHARACTER SET = utf8;

USE friendDB;

CREATE TABLE person
(
    pid INTEGER PRIMARY KEY,
    name VARCHAR(30)
);

CREATE TABLE friends
(
    pid INTEGER,
    friend INTEGER,

    CONSTRAINT fk_person_pid FOREIGN KEY (pid) REFERENCES person(pid),
    CONSTRAINT fk_person_friend_pid FOREIGN KEY (friend) REFERENCES person(pid),

    PRIMARY KEY (pid, friend)
);


insert into person values(1,'Max');
insert into person values(2,'Moritz');
insert into person values(3,'Fritz');
insert into person values(4,'Franz');
insert into person values(5,'Heinz');
insert into person values(6,'Josef');
insert into friends values(1,2);
insert into friends values(2,3);
insert into friends values(1,4);
insert into friends values(3,5);
insert into friends values(2,6);
insert into friends values(1,5);