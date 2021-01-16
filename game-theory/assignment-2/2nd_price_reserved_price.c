#include <stdio.h>

double revenue(double,double,double,double);
double find_second(double,double,double);
double find_second_2(double,double,double);
double max(double,double);
double run_auction(double);

static double DELTA = 0.01;
static double MAX_PLAYER_BID = 1.0;

int main() { 
    double reserved_prices[10] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    int count = sizeof(reserved_prices)/sizeof(double);

    int i = 0;
    int number_of_iteration = MAX_PLAYER_BID / DELTA;
    int total_number_of_iterations = number_of_iteration * number_of_iteration * number_of_iteration;
    printf("Start auctions with delta: %lf, it will take some time, number of iterations: %d\n**********************************************\n\n\n", DELTA, total_number_of_iterations);
    for (i = 0; i < count; i++) {
        double r_p = reserved_prices[i];
        double revenue = run_auction(r_p);        
        printf("reserved price: %lf, price is: %lf\n", r_p, revenue);
    }
}

double run_auction(double reserved_price) {
  double player1;
  double player2;
  double player3;

  double init_value = 0.0;
  double total_by_reserved_price = 0.0;
  
  for(player1 = init_value; player1 <= MAX_PLAYER_BID; player1 += DELTA) {
    for(player2 = init_value; player2 <= MAX_PLAYER_BID; player2 += DELTA) {
      for(player3 = init_value; player3 <= MAX_PLAYER_BID; player3 += DELTA) {
          double _revenue = revenue(player1, player2, player3, reserved_price);
          total_by_reserved_price += _revenue;
        }
      }
    }
    printf("==============================================\n");
    return  total_by_reserved_price * DELTA * DELTA * DELTA;
}

int winner_exists(double x, double y, double z, double reserve) {
  double max1 = max(x, y);
  double max2 = max(y, z);
  double max3 = max(max1, max2);
  return max3 >= reserve;
}

double revenue(double x, double y, double z, double reserve) {
    if(winner_exists(x, y, z, reserve) == 0) {
      return 0;
    }
    double second = find_second(x, y, z);
    
    if(x == y && y == z) return z;
    return max(second, reserve);
}

double max(double a, double b) {
    if(a > b) return a;
    else return b;
}

double find_second(double a, double b, double c)                                                           
{                                                              
     // a is the largest
    if(a >= b && a >= c)
    {
        if(b >= c) return b;
        else return c;
    }
    else if(b >= a && b >= c) {
        if(a >= c) return a;
        else return c;        
    }
    // c is the largest number of the three
    else if(a >= b) return a;
    else return b;
}