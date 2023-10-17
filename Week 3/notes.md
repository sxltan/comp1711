# Week 3 Notes

## Objectives

1. If... Else
2. Switch

## Conditions and Comparisons

```python
IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE
{
    CODE IF FALSE
}
```

### Advanced Version (Chain):

```python
IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE IF (CONDITIONAL_TEST)
{
    CODE IF TRUE
}
ELSE
{
    CODE IF FALSE
}
```

## Switch

A switch can be a neater way of testing against multiple values (rather than conditions).   
It's also great for providing simple meny systems.  

```python
switch (VARIABLE) {

        case 0: printf ("Option 0 has been selected\n");
        break;

        case 1: printf ("Option 1 has been selected\n");
        break;

        default: printf ("A different option has been selected\n");
    }
```

- Opening line is switch (with variable in brackets)
- This is tested against the various cases (EACH CASE IN ORDER)
- Final line is default (executed if none of the cases match)
- "Break" is there so that not ALL the other options get executed