# CS 499 Capstone – Christian Foster

Welcome to my CS 499 Capstone ePortfolio repository. This portfolio highlights my academic journey and the technical growth I’ve achieved through the Computer Science program at Southern New Hampshire University. It includes enhanced artifacts in software engineering, algorithms and data structures, and database development, along with documentation and reflections that demonstrate my readiness for real-world development work.

## Artifacts Overview

### 1. ABCU Course Planner (C++)  
**Course:** CS 300 – Data Structures and Algorithms Analysis and Design  
- Uses a Binary Search Tree to store and retrieve course data.
- Enhanced for recursive prerequisite validation, cleaner parsing, and improved memory handling.

### 2. GameService Singleton (Java)  
**Course:** CS 230 – Operating Platforms  
- Implements a Java singleton to manage game and team objects.
- Refactored for encapsulation, logic clarity, and best practices in object-oriented design.

### 3. Animal Shelter Data Handler (Python)  
**Course:** CS 340 – Client/Server Development  
- Connects to MongoDB to retrieve and display animal shelter data.
- Enhanced for modularity, secure connection handling, and integrated logging.


**Professional Self-Assessment**

Throughout my journey at Southern New Hampshire University (SNHU), I’ve grown tremendously in my knowledge and application of computer science principles. My capstone project gave me the opportunity to reflect on the progress I've made, especially in the areas of software engineering, data structures, databases, algorithms, collaboration, and cybersecurity. Coming from a background that includes military experience, IT support roles, and hands-on coding assignments, I’ve developed both technical and soft skills that prepare me for the demands of a professional environment.

**Team Environments**

While completing my degree, I had the chance to work on several individual and collaborative assignments, which taught me how to build solutions while working with a team. Although most of my projects were completed individually due to the structure of SNHU’s online environment, I maintained communication with peers through discussion boards, peer reviews, and Brightspace forums. These interactions taught me how to explain technical issues in a clear and respectful way. Additionally, my military background has ingrained in me a strong sense of accountability, teamwork, and discipline, all of which transfer directly to working on collaborative software teams.

**Communicating to Stakeholders**

My courses helped me understand the importance of clear communication between developers and stakeholders. In CS 250: Software Development Lifecycle and CS 310: Collaboration and Team Project, I learned how to document user requirements and translate them into technical specifications using tools like UML diagrams. These courses emphasized the importance of designing solutions that not only solve the technical problem but also align with business goals. Communicating technical plans to a non-technical audience is something I’ve practiced through milestone reports and enhancement essays in multiple courses.

**Data Structures and Algorithms**

One of the most rewarding experiences was working on my artifact from CS 300: Data Structures and Algorithms Analysis and Design. I created a course planner using a binary search tree to organize and search through academic course information. Enhancing this artifact taught me how to optimize search and validation logic, handle file parsing efficiently, and use recursive traversal effectively. Through this, I learned the value of selecting the right data structure for a task and how the choice can impact performance and reliability.

**Software Engineering and Databases**

My exposure to database development came through CS 340: Client/Server Development. I built a Python script (animal_shelter.py) that connects to a MongoDB database, queries animal records, and structures the output in a clean and maintainable format. I enhanced the script by adding modular functions, logging, exception handling, and secure connection practices. These improvements mirrored what software engineers do in real-world projects when working with databases. Similarly, my project in CS 230: Operating Platforms introduced me to Java design patterns through the GameService.java singleton. Enhancing this taught me how to clean up class structure, use encapsulation, and follow best practices in object-oriented design.

**Security**

Security has always been a concern for me, especially after working in the military and IT support. At SNHU, I learned how to secure data connections, sanitize inputs, and avoid memory leaks or buffer overflows. These lessons were applied directly in my enhanced Python and C++ projects. For instance, in animal_shelter.py, I replaced hardcoded credentials with secure credential handling and added error logging. In my C++ course planner, I focused on safe memory allocation and proper input validation. These small steps are crucial in preventing vulnerabilities in real applications.

****Inclusion of Artifacts****

For this project, I selected three artifacts that showcase my range of skills across software engineering, algorithms, and databases:

GameService.java from CS 230: Operating Platforms – demonstrates object-oriented software design and Java singleton pattern.

animal_shelter.py from CS 340: Client/Server Development – highlights secure database access and modular Python scripting.

ABCU_Project.cpp from CS 300: Data Structures and Algorithms Analysis and Design – showcases algorithmic thinking, recursion, and binary search trees.

Each artifact was enhanced with better logic, structure, and security. Together, they reflect the evolution of my coding style and my ability to solve real-world problems using appropriate tools and methodologies.

Conclusion This capstone has helped me bring together everything I’ve learned at SNHU and demonstrate it in a meaningful way. My enhanced artifacts serve not just as code samples, but as proof of my growth, discipline, and readiness to contribute as a professional in the computer science field. With a strong foundation in software development, algorithms, databases, and security, I feel confident in stepping into roles that demand both technical excellence and responsible problem-solving.

****Code Review Reflection Essay****

For my CS 499 capstone project, I conducted an informal code review of three enhanced software artifacts that represent my growth and mastery in computer science: a Java-based GameService singleton (GameService.java) from CS 230: Operating Platforms, a Python MongoDB script for an animal shelter database (animal_shelter.py) from CS 340: Client/Server Development, and a C++ course planner that implements a binary search tree (ABCU_Project.cpp) from CS 300: Data Structures and Algorithms Analysis and Design. This review process allowed me to reflect on my original implementations, evaluate areas for improvement, and identify opportunities to apply design principles, improve security, and adopt professional coding practices. The review contributed directly to meeting the learning outcomes of the capstone course.

In the GameService Java class (GameService.java), created during CS 230, I initially developed a singleton service to manage games, players, and teams. During review, I noticed redundant logic and inconsistencies in static variable usage. My review led to simplification of the addGame() method, better use of enhanced for-loops, and a shift toward clearer naming conventions. I also reinforced proper encapsulation and added comments to improve collaboration. These updates strengthened the structure of the code and helped align it with software design principles and object-oriented best practices.

The Python animal shelter script (animal_shelter.py), completed during CS 340, originally connected to a MongoDB collection and printed raw data. During review, I found several security and structural flaws, including hardcoded credentials, unmodular logic, and the absence of logging. My enhancements addressed these by creating a reusable get_database_connection() function, integrating the logging module, and adding exception handling. These changes increased security and usability, aligning the artifact with database and software security outcomes.

Finally, my C++ artifact, the ABCU Course Planner (ABCU_Project.cpp), developed in CS 300, used a binary search tree to store and display course information. My review identified inefficient file parsing, weak validation of prerequisites, and unnecessary use of dynamic memory. I corrected these by rewriting parsing logic using stringstream, replacing new with stack allocation, and fixing recursive traversal for prerequisite checks. I also improved prompts and input validation, making the program more user-friendly and reliable.

Through this code review process, I demonstrated the ability to analyze my own work critically, adopt secure and efficient coding practices, and document decisions for peer collaboration. This experience emphasized the importance of maintainability, logic clarity, and professional communication in software engineering. The enhancements made from my review not only improved the artifacts but also showed how I have grown as a developer ready to contribute to real-world technical environments.
