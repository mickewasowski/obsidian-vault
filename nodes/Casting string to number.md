---
aliases:
context:
- "[[Computer science]]"
---

# Casting string to number

---
In C to convert a string to it's number equivalent a few operations are performed:

1. First we calculate the string character's integer value - this is done by subtracting the value of '0'
```c
'0' - '0' -> 0 (in C '0' is 48)
'1' - '0' -> 1 // 49
'2' - '0' -> 2 // 50
```

2. With each converted character we need to multiply by 10 and then add the new number
```c
'437' -> 437
```

Example code in C:
```c
int str_to_int(char *str){
    int result = 0;
    for (int i = 0; str[i] != '0'; i++){
        if (str[i] < '0' && str[i] > '9')
            return -1;

        result = (result * 10) + (str[i] - '0');
    }
    
    return result;
}
```

