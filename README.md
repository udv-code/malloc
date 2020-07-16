# Malloc
Simple memory allocator header-only library written in C.
## Usage
Just clone repository and use code:
```
git clone https://github.com/udv-code/malloc <dir>
```
Or you can use it with CMake:
```CMake
# ...
option(MALLOC_BUILD_SANDBOX OFF)
add_subdirectory(<malloc-directory>)

target_link_libraries(
    <target-name>
    PRIVATE
    ${MALLOC_TARGET_NAME}
)
# ...
```
Or compile by hand:
```
$ gcc -o umalloc.so -fPIC -shared umalloc.c
```
### Notes
- `sbrk` function is used from `unistd.h` header. For now only linux-based systems support build.
