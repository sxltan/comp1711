# Week 9 Notes

## Pointers Info

`Int*` = A variable that would store the address of another variable that contains integer data.

General format = `<data type>* <variable_name>`

`%p` = Format specifier to print pointers

`&` = ”Address of” operator

`*p` = “Content of the address” operator

## Pointers in Arrays

No restriction on “how many data” the target variable has.

- Can contain even addresses to arrays.

- Assignment “address = vector” assigns the address of the first element ofthe array “vector”.
  
## Pointer Arithmetic

- Assignment “`address = vector`” assigns the address of the first element of thearray “vector”.
- `(address + 1)` = computes the address of the next cell.
- `(address + 2 )` = computes the address of the third cell.• Address + k = ??
---
- `++` operator = Add and assign.
- `*address++` = Access the value first, then add.
- `*++address` = ?

## Dynamic Memory Allocation

````c++
int* vector = (int *) malloc (sizeof(int)* array_size)
````

- `Malloc ( k )` : allocates at least ‘k’ bytes of memories.
- k = `sizeof (int) * array_size` (You calculate the size:)
- Malloc returns a void type pointer.
- You typecast it to `int`.

## Linked Lists

Singly Linked List - A linear data structure in which the elements are not stored in contigious memory locations and each element is connected only to its next element using a pointer.

```c++
void *malloc(size_t size)
```

- Size : This is the size of the memory block, in bytes.
- Return Value : This function returns a pointer to the allocated memory, or NULL if the request fails.

```c++
first_node.next_element = (list*) malloc(sizeof(struct list));
```

- Dynamically create a new element, find out where it is, and then allocate the memory needed into the next element address

```c++
first_node.next_element = (list*) calloc(sizeof(struct list),1);
```

- Calloc() initialises things to 0