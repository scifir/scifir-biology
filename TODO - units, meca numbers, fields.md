// FINISH ACTUAL UNITS
// TODO: Correct the operator - of vector_unit

// NEARLY-FINISHED TASKS
// TODO: initialize_real_dimensions() of class auto_unit and check initialization of dimensions
// TODO: check if dynamic_cast is the only solution for left-hand operators. If so, change it inside auto_scalar.hpp too if needed. Find out the performance of dynamic_cast related to the performance of static_cast
// TODO: abbreviation_electron_volt should have the factor E-19 enabled

// FINISH ACTUAL MECA NUMBERS
// TODO: Try that class lab_number doesn't use print, instead it should use operator << always
// TODO: Use print() inside unit to print the unit for vector_units too
// TODO: operator << and maybe print() for direction
// TODO: Bidirectional operators of meca_numbers for numbers
// TODO: meca_number class for angle_number class
// TODO: angle_number should invalidate when the unit given is not empty
// TODO: angle_number class doesn't has their functions finished

// PROPERLY DISPLAY OF UNITS
// TODO: display vector_unit with the proper angles for each nd case
// TODO: unit_number should display with the proper locale
// TODO: Reduce linker libraries needed for boost::locale (see if the libraries aren't needed and delete them)
// TODO: auto display in the units that closely match the value (100 or less is the unit selected, if it's more than 1000 it's the prefix 10^3 bigger, and if it's less than 0.1 it has to display in the previous 10^-3 prefix)

// ARCHITECTURE OF UNITS
// TODO: Change the shared_ptr of both dimension containers to a unique_ptr

// MECA NUMBERS
// TODO: Add the operators += -= *= etc to the number classes, and change the get_value().get_value() to get_value()
// TODO: undefined_number_union containing all the undefined_number derived classes. It shouldn't contain angle_number. Try first with a union of smart pointers, after with a undefined_number and a dynamic_cast inside unit.hpp, if it doesn't work a pointer, and if it doesn't work a union.
// TODO: Add names to the meca numbers (angler, laber, etc)
// TODO: The meca number class and it's kernel derived classes
// TODO: The interval number class
// TODO: The interval number subclasses of other numbers
// TODO: The bounce number class
// TODO: The percentage number class
// TODO: Implement the bounce number in the spherical coordinates and the hyperspherical coordinates
// TODO: Solve the problem with left and right repeated (it's not exclusive for direction_symbol)
// TODO: solid_angle class (maybe it isn't a meca number)
// TODO: maybe _angle for angle_number in order to use cos(x),sin(x),etc with degrees

// VECTOR FIELDS
// TODO: vector_field (it should operate with vector_units and maybe with scalar_units. With (x,y,z) it gives the respective vector). +, - and ^ with vector_field, + - * with vector_unit
// TODO: Typecasting of vector_unit to math_vector, boost_Ublas_vector, etc. Same for math_vector to vector_unit
// TODO: rotational coordinates

// ADDITIONAL CHARACTERISTICS OF UNITS
// TODO: mass of standard_atomic_mass() is displayed [empty], fix it
// TODO: custom_dimension in order to have custom dimensions
// TODO: change dimension_abstract name to abstract_dimension
// TODO: pixel dimension, pixel unit and pixels_distance classes
// TODO: delete the exceptions from constructors and other parts where it's unneeded
// TODO: see what to do for units with the same dimensions at the numerator and at the denominator
// TODO: default zero units for the cases of errors with operators (unit, scalar and vector). see first if to use exceptions instead
// TODO: vector unit should have display_as_scalar() function
// TODO: see if to implement coordinates classes as composition instead of multiple-inheritance
// TODO: operator == should care about dimensions and the value related to dimensions (cast operator == of unit,unit there)
// TODO: initialization of 1/g and similar
// TODO: support scientific notation on constructors and display(int,bool) (check if there's a function to get the order of the number)
// TODO: units updated with a clock (not automatically, by doing += and similar operations)
// TODO: 2d display of scalar_units and of vector_units
// TODO: 3d display of scalar_units and of vector_units
// TODO: maybe create_dimension(), create_abbreviation() and create_prefix() should have parameters to pass to constructors
// TODO: create_abbreviation() should forbid some constructions
// TODO: operator >> should allow to create vectors giving angles
// TODO: unit time class should be initialized by multiple abbreviations as 100 min 40 s for example
// TODO: unit time class should display with an string "d s" specifying the dimensions to calculate on
// TODO: divide single dimensions unit of multiple-dimensions unit in order to save a lot of space by not using vectors of prefixes, dimensions and abbreviations
// TODO: volume should be constructed with an string of the form 2cm * 1cm * 3cm and separate the three dimensions as different units. Also, the display should be, for that case, automatically configured to be 2cm * 1cm * 3cm than to be the total amount (with a member-variable)
// TODO: units should allow to sum strings
// TODO: the pH should be an special unit

// UNITS - ADVANCED
// TODO: support currency dimension

// PATTERNS
// TODO: implement a pattern class using a regular expressions library