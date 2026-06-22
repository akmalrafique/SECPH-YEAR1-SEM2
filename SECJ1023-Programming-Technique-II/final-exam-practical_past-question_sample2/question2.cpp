

// a)i) Student and Address-> indirect composition,students inherits from Person class,person class has composition relationship with adress
//indicates with solid black diamond.because student "is a" person,the student inherently own an Adress whose is strictly bound to it.
//ii)Student and Advisor->aggregation realtionship,student HAS AN advisor,inidcates by hollow diamond.its a weak relationship where
//advisor can exist independantly even if object student is destroyed
//iii)Advisor and Person->the relationship is inheritance(generalization).indicated by the open triangle arrow pointing from Advisor to the Person base class.
//advisor "is a "specific type of person which inherits its attribute and method.
//Yes, structurally, an advisor can conceptually have more than one student under them.
//Justification: In an aggregation relationship, multiple Student objects can contain a pointer or reference to the exact same Advisor object. However,
//it is important to note that based on this specific UML diagram, the Advisor class itself does not contain a list or array to track those students internally.
//
//
//
//
//
