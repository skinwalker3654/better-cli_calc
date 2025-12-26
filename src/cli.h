#ifndef CLI_H
#define CLI_H

// Commands
#define addition        "add"
#define subtraction     "sub"
#define multiplication  "mul"
#define division        "div"
#define power_numbers   "pow"
#define factorial       "--fac"
#define modulo          "mod"
#define round_nums      "--round"
#define sqrt_num        "--sqrt"
#define log_num         "--log"
#define max_nums        "max"
#define min_nums        "min"
#define help_comand     "--help"

// Function declarations
float add_nums(float a, float b);
float sub_nums(float a, float b);
float mul_nums(float a, float b);
float div_nums(float a, float b);
float pow_nums(float a, float b);
float round_num(float a);
float square_root(float a);
int mod_nums(float a, float b);
float max_num(float a, float b);
float min_num(float a, float b);
int factorial_of(float a);
float log_of(float a);
void help_info(void);

#endif

