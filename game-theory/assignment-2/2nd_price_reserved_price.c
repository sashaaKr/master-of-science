#include <stdio.h>

double revenue(double,double,double,double);
double find_second(double,double,double);
double find_second_2(double,double,double);
double max(double,double);
double run_auction(double, double);

int main() {
    double delta = 0.01;    
    double reserved_prices[10] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    int i = 0;

    for (i = 0; i < 10; i++) {
        double r_p = reserved_prices[i];
        double revenue = run_auction(r_p, delta);        
        printf("reserved price: %lf, price is: %lf\n", r_p, revenue);
    }
}

double run_auction(double reserved_price, double delta) {
  double player1;
  double player2;
  double player3;

  double init_value = 0.0;
  double total_by_reserved_price = 0.0;

  for(player1 = init_value; player1 <= 1.0; player1 += delta) {
    for(player2 = init_value; player2 <= 1.0; player2 += delta) {
      for(player3 = init_value; player3 <= 1.0; player3 += delta) {
          double _revenue = revenue(player1, player2, player3, reserved_price);
          total_by_reserved_price += _revenue;
        }
      }
    }
    return  total_by_reserved_price * delta * delta * delta;
}

int winner_exists(double x,double y,double z,double reserve) {
  double max1 = max(x,y);
  double max2 = max(y,z);
  double max3 = max(max1,max2);
  return max3 >= reserve;
}

double revenue(double x,double y,double z,double reserve) {
    if(winner_exists(x,y,z,reserve)==0) {
      return 0;
    }
    double second = find_second(x,y,z);
    
    if(x==y && y==z){
      return reserve;
    }
    return max(second,reserve);
}

double max(double a, double b) {
    if(a > b)
        return a;
    else
        return b;
}

double find_second(double a, double b, double c)                                                           
{                                                              
    if (a==b&&a>c) return c ;
    if (a==c&&a>b) return b ;
    if (b==c&&b>a) return a;

     // a is the largest
    if(a >= b && a >= c)
    {
        if(b >= c)
          return b;
        else
          return c;
        
    }
    else if(b >= a && b >= c) {
        if(a >= c)
          return a;
        else
          return c;        
    }
    // c is the largest number of the three
    else  if(a >= b)
        return a;
    else
      return b;
}