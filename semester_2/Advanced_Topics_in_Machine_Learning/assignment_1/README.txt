### NOTES ###
===# 1 #===
Attempt to add stratification by price before train_and_split failed on error
"ValueError: The least populated class in y has only 1 member, which is too few. The minimum number of groups for any class cannot be less than 2"
I wondered why, and turns out simple stratification doesn't fit for continious variable as price.
Here is some good explanation on the case
https://danilzherebtsov.medium.com/continuous-data-stratification-c121fc91964b
Here is simple code workaround to turn continious data into categorical
https://michaeljsanders.com/2017/03/24/stratify-continuous-variable.html
