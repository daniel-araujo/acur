#include "acur.h"

size_t acur_data_index(struct acur *c, size_t index);

void acur_init1(struct acur *c, size_t element_size, void *data, size_t size);

void acur_init2(struct acur *c, size_t element_size, void *start_data, void *end_data);

void acur_init3(struct acur *c, size_t element_size, void *data, size_t start_index, size_t end_index);

int acur_finished(struct acur *c);

void acur_rewind(struct acur *c);

void *acur_data(struct acur *c);

size_t acur_index(struct acur *c);

void *acur_element(struct acur *c);

size_t acur_size(struct acur *c);

void *acur_begin(struct acur *c);

void *acur_end(struct acur *c);

void acur_next(struct acur *c);
