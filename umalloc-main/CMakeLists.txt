# Helper vars
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MALLOC_BINARY_DIR ${${MALLOC_TARGET_NAME}_BINARY_DIR}/${CURRENT_DIR})
set(MALLOC_SOURCE_DIR ${${MALLOC_TARGET_NAME}_SOURCE_DIR}/${CURRENT_DIR})

# Target
add_library(
		${MALLOC_TARGET_NAME}
		SHARED
		include/umalloc/common.h
		include/umalloc/malloc.h

		src/malloc.c
)

add_library(
		${MALLOC_PROJECT_NAME}::${MALLOC_TARGET_NAME}
		ALIAS
		${MALLOC_TARGET_NAME}
)

target_include_directories(
		${MALLOC_TARGET_NAME}
		PUBLIC
		$<BUILD_INTERFACE:${MALLOC_BINARY_DIR}/include>
		$<BUILD_INTERFACE:${MALLOC_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		PRIVATE
		src
)