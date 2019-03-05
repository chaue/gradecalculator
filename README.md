# Simple Grade Calculator using QT(PIC10C Assignment #2)
Displays grade for a class based on homework assignments and exams

__Implementation__
* I created this application using QT Creator.
* Scores for assignments can be set using the spinbox or slider and the class grade will be updated automatically as you go

__Update #1__
* got the basic slots and signals working between one slider, spinbox, and label(which displays your grade)
* simplified code to allow the member function that updates the label to extract the values directly from the spinbox(and by extension the slider)

__Update #2__
* condensed the connecting statements and update labels function by storing the homework spinboxes and sliders into respective vectors
* iterating through the vector with a for loop made the code much cleaner and easier to read
* had to add a vector private member to store the spinboxes since the updatelabels function wouldn't work with a vector initialized in the gradeCalc constructor
* couldn't construct a vector with all the spinboxes and directly assign it to the private member, so I had to settle for using the copy constructor
