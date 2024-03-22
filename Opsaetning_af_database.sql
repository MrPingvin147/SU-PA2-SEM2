create schema robot_worker;
use robot_worker;

CREATE TABLE robot (
    task_id INT AUTO_INCREMENT,
    description CHAR(125) NOT NULL,
    time INT NOT NULL,
    PRIMARY KEY (task_id)
);

Insert into robot (description, time) values 
("Clean bin", 125),
("Clean sink", 24),
("Clean floor", 26),
("Clean toilet", 62),
("Clean clothes", 12),
("Dry clothes", 62),
("Fold clothes", 123);

SELECT * FROM task;

CREATE TABLE robot (
    name VARCHAR(255) NOT NULL,
    current_task INT,
    PRIMARY KEY (name),
    FOREIGN KEY (current_task)
        REFERENCES task (task_id),
    UNIQUE (current_task)
);