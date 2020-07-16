# Malloc
Simple memory allocator in C.
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