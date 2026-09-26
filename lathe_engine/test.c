//
//  test_main.c
// just test the basics of the engine really.
//  lathe_tools
//
//  Created by Christopher Scott on 9/20/26.
//

#include "math/lathe_mat3.h"
#include "math/lathe_vec3.h"
#include "memory/lathe_memory.h"
#include "system/lathe_logger.h"
#include <assert.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  lathe_vec3 v = {5, 25, 5};
  //
  FILE *fptr;
  fptr = fopen("LogFile", "a");

  vec3_print(&v, stderr);
  v = vec3_negate(&v);
  vec3_print(&v, NULL);

  lathe_vec3 n = vec3_normalize(&v);
  vec3_print(&n, nullptr);
  lathe_vec3 d = vec3_add(&v, &v);
  vec3_print(&d, fptr);
  //   lathe_mat_3x3 m = create_3x3_matrix_vec3(&d, &d, &d);
  //   lathe_mat_3x3 m2 = create_3x3_matrix_vec3(&d, &d, &d);
  //   printf("%f\n", m.m[0][0]);
  //   mat_3x3_print(&m, NULL);
  //   mat_3x3_print(&identity_3x3, fptr);
  //
  //   lathe_mat_3x3 i = mat_3x3_mul_mat_3x3(&m, &m2);
  //   mat_3x3_print(&i, NULL);

  //   i.m[2][0] = 1.6f;
  //
  //   lathe_vec3 tw = get_mat_3x3_row(&i, 2);
  //
  //   vec3_print(&tw, NULL);
  //   float mag = vec3_magnitude(&n);
  //   printf("%f\n", mag);
  //   lathe_mat_3x3 ma = {
  //       .m = {{1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}}};
  //
  //   lathe_vec3 ve = {1.0f, 2.0f, 3.0f};
  //
  //   lathe_vec3 result = mat_3x3_mul_vec3(&ma, &ve);
  //   assert(result.x == 14.0f);
  //   assert(result.y == 32.0f);
  //   assert(result.z == 50.0f);
  //   vec3_print(&result, NULL);
  //
  //   // Memory Test - Can use malloc or stack
  //   // void *backing_buf = malloc(LATHE_1KB);
  //
  //   unsigned char backing_buf[LATHE_1KB];
  //   lathe_arena arena = {};
  //   arena_init(&arena, backing_buf, LATHE_1KB);
  //   int *z = (int *)arena_allocate(&arena, sizeof(int));
  //   if (z == nullptr) {
  //     printf("Theres nothing we can do\n");
  //   } else {
  //     *z = 1;
  //
  //     printf("%p %d\n", z, *z);
  //   }
  //
  //   void *should_fail = arena_allocate(&arena, SIZE_MAX / 2); // may
  //   overflow...
  //
  //   arena_free_all(&arena);
  //
  //   printf("%p %c\n", z, *z);

  LATHE_FATAL("This is FATAL!", nullptr);
  LATHE_WARN("This is a warning!", nullptr);
  LATHE_ERROR("This is an ERROR", stdout);
  LATHE_INFO("This is just for information", NULL);
  LATHE_TRACE("This is a trace msg", NULL);
  LATHE_DEBUG("debugger msg", nullptr);
  // free(backing_buf);
  fclose(fptr);
}
