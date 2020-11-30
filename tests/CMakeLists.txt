function(test_single_c_file target)
    add_executable(${target} ${target}.c)
    target_link_libraries(${target} acur)
    add_test(NAME ${target} COMMAND ${target})
endfunction(test_single_c_file)

test_single_c_file(init)
test_single_c_file(iter)
