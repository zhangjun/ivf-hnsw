
#include "utils.h"

void random_subset(const float *x, float *x_out, int d, int nx, int sub_nx) {
    int seed = 1234;
    std::vector<int> perm(nx);
    faiss::rand_perm(perm.data(), nx, seed);

    for (int i = 0; i < sub_nx; i++)
        memcpy(x_out + i * d, x + perm[i] * d, sizeof(x_out[0]) * d);
}
