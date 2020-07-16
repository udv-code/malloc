set(MALLOC_EXAMPLE_TARGET_NAME "${MALLOC_PROJECT_NAME}-example")

add_executable(
		${MALLOC_EXAMPLE_TARGET_NAME}
		example.c
)

target_link_libraries(
		${MALLOC_EXAMPLE_TARGET_NAME}
		PRIVATE
		${MALLOC_TARGET_NAME}
)