drop user if exists user_myblog@localhost;
create user user_myblog@localhost identified by 'htl';
drop database if exists myblog;
create database myblog default character set utf8 default collate utf8_general_ci;
use myblog;

grant all privileges on myblog.* to user_myblog@localhost;

create table category(
	id int(11) auto_increment,
	name varchar(255),
	primary key(id),
	created_at datetime default current_timestamp
);

CREATE TABLE posts (
  id int(11) NOT NULL AUTO_INCREMENT,
  category_id int(11),
  title varchar(255),
  body text,
  author varchar(255),
  created_at datetime default current_timestamp,
  PRIMARY KEY (id),
  foreign key(category_id) references category(id)
);
insert into category(name) values('Technology');
insert into category(name) values('Sports');
insert into category(name) values('Cars');
insert into category(name) values('Books');

insert into posts(category_id,title,body,author) values(1,'Technology Post One','AI godfather Geoffrey Hinton warns of dangers as he quits Google','Ham');
insert into posts(category_id,title,body,author) values(1,'Technology Post Two','IBM Says 7,800 Jobs (or Nearly 30% of Its Workforce) Could Be Replaced By AI','Bra');
insert into posts(category_id,title,body,author) values(1,'Technology Post Three','Experiment Puts AI Voices and Music on Radio in Switzerland','Bra');
insert into posts(category_id,title,body,author) values(2,'Sports Post One','Lionel Messi suspended by Paris St-Germain for two weeks over Saudi Arabia trip','Ham');
insert into posts(category_id,title,body,author) values(2,'Sports Post Two','Madrid Open: Carlos Alcaraz sails through to quarter-finals but Daniil Medvedev beaten','Bra');
insert into posts(category_id,title,body,author) values(3,'Cars Post One','Elon Musk\'s Tesla cuts prices again as tries to boost sales','Bra');
