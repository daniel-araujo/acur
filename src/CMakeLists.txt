add_library(acur acur.c acur.h)

set_target_properties(acur PROPERTIES C_STANDARD 11)

# Error messages: the more the better.
target_compile_options(acur PRIVATE -Wall -Wextra)

# Turn certain warning messages into error messages.
target_compile_options(acur PRIVATE -Werror=incompatible-pointer-types)

# Suppress less desirable warning messages.
target_compile_options(acur PRIVATE -Wno-unused-variable)
