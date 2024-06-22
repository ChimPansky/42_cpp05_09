#C-style casting:

```C
float	f = 42.24f;
int		x = (int)f; // convert float to int
```

#C++-style casting:

##static casting:
used for well-defined and non-polymorphic conversions such as converting between related data types (e.g. char/int/float/double... or char*/int*/float*/double*...)
```C++
float	f = 42.24f;
int		x = static_cast<int>(f); // convert float to int
```

##dynamic casting:

```C++
float f = 42.24f;
```

##const casting:


##reinterpret casting:
