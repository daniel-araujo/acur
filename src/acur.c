#include "acur.h"

extern inline size_t acur_data_index(struct acur *c, size_t index);

extern inline void acur_init(struct acur *c, size_t element_size, void *data, size_t size);

extern inline void acur_init1(struct acur *c, size_t element_size, void *data, size_t size);

extern inline void acur_init2(struct acur *c, size_t element_size, void *start_data, void *end_data);

extern inline void acur_init3(struct acur *c, size_t element_size, void *data, size_t start_index, size_t end_index);

extern inline int acur_finished(struct acur *c);

extern inline void acur_rewind(struct acur *c);

extern inline void *acur_data(struct acur *c);

extern inline size_t acur_index(struct acur *c);

extern inline void *acur_element(struct acur *c);

extern inline size_t acur_size(struct acur *c);

extern inline void *acur_begin(struct acur *c);

extern inline void *acur_end(struct acur *c);

extern inline void acur_next(struct acur *c);
