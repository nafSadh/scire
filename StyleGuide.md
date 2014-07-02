----------------------
  scire style guide
----------------------

Code Formatting
---------------
 
 with AStyle: 
 --style=kr --indent=spaces=2 --indent-modifiers --indent-namespaces --mode=c

Naming Conventions
------------------

  1. ClassNames are in UpperCamelCase
  2. ClassPublicFunction names are in UpperCamelCase
  3. PropertyNames are in UpperCamelCase (properties are public)
  4. private/protected class members are in lowerCamelCase
  5. local variables are in lowerCamelCase, oftnAbbr.
  6. DEFINE_THINGS in UPPER_CASE
  7. functions arguments shall be descriptivelyNamed
      ctor args may have trailing underscores_ to disambiguate
      when have one arg_ with trailing _, suffix all args of same func with it
  8. a Property is associated with
      -  type Property(){} as public getter function
      -  void Property(type){} as public setter function
      -  type theProperty or property as associated (protected/private) field
  9. IAllInterface names has 'I' prefixed to its name
 10. AClassThatIsAbstract has 'A' prefixed to its name


Other Conventions
-----------------

  1. local variables shall be declared near place of use
  2. function local variables that is used throughout can be at top
  3. class members shall be accessed this-> to avoid confusion, unless it is a
      field associated with some property and prefixed the.
  4. no class field shall ever be public, use getter and setters
  5. use protected access modifiers, whenever possible instead of private to
     allow class inheritance
  6. classes shall not inherit more than one class directly
  7. use interfaces and abstract classes
  8. PureVirtualFunctions() = 0;
  9. ctors are generally explicit
 10. dtors are generally virtual
 11. pure abstract classes has private ctors
 12. ctors will call : member(val) styled initializers
 13. a class that is ABSTR has a virtual dtor and vice versa
 14. Interfaces are named with 'I' prefixed, have only pure virtual functions, 
      no fields, and no explicit ctor nor dtor
 15. Class member function definitions when written outside class, generally
      do not have any comment header. Hence, use of two newlines to seperate
      functions is advised. Also put the func name in newline, when there is 
      a long template associated with it. 
 16. file_name shall be all lower case and will use underscores.
  
ifdef Conventions
-----------------
  
  1. for files: SCIRE_directory_filename_EXT
  2. for class: SCIRE_ClassName_CLASS
  3. for interface: SCIRE_NameOfInterface_INTFC , i.e. macro drops the prefix
  4. for abstraction: SCIRE_AbsractClass_ABSTR , i.e. macro drops the prefix
  5. for class with static functions only: SCIRE_ClassName_FUNCS


Shorthands
----------
  
  1. lhs, rhs = left (right) hand side (operands)
