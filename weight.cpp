#include <vector>
#include <iostream>
int main(){


  std::vector<int> val, wt;

    // traverse the original cost[] array and skip
    // unavailable packets and make val[] and wt[]
    // array. size variable tells the available number
    // of distinct weighted packets
  int size = 7;
  int W = 50;



  wt.push_back(15);
  wt.push_back(25);
  wt.push_back(45);
  wt.push_back(30);
  wt.push_back(23);
  wt.push_back(37);

  val.push_back(100);
  val.push_back(350);
  val.push_back(225);
  val.push_back(67);
  val.push_back(275);
  val.push_back(168);

  int n = size;
  int min_cost[n+1][W+1];
  int bagWt[n+1][W+1];

    // fill 0th row with infinity
  for (int i=0; i<=W; i++){
    min_cost[0][i] = 0;
    bagWt[0][i]=0;
  }
    // fill 0'th column with 0
  for (int i=1; i<=n; i++){
    min_cost[i][0] = 0;
    bagWt[i][0]=0;
  }

    // now check for each weight one by one and fill the
    // matrix according to the condition
  for (int i=1; i<=n; i++){
    for (int j=1; j<=W; j++){
            // wt[i-1]>j means capacity of bag is
            // less then weight of item
      if (wt[i-1] > j){
        min_cost[i][j] = min_cost[i-1][j];
        bagWt[i][j] = bagWt[i-1][j];
      }else{
        if(wt[i-1]+bagWt[i-1][j]>j && val[i-1] > min_cost[i-1][j]){
         min_cost[i][j]=val[i-1];
         bagWt[i][j]=wt[i-1];
       }else{
         if(min_cost[i-1][j]>min_cost[i][j-1] + val[i-1]){
          min_cost[i][j]=min_cost[i-1][j];
          bagWt[i][j]=bagWt[i-1][j];
        }
        else{
          if(wt[i-1]+bagWt[i-1][j]<51){
           min_cost[i][j] = min_cost[i-1][j-1]+val[i-1];
           bagWt[i][j]=bagWt[i-1][j-1]+wt[i-1];
         }else{
           if(val[i-1]+min_cost[i-1][j-1]>min_cost[i-1][j] && wt[i-1]+bagWt[i-1][j-1] < 51){
            min_cost[i][j] =val[i-1]+min_cost[i-1][j-1];
            bagWt[i][j]=wt[i-1]+bagWt[i-1][j-1];
          }else{
            min_cost[i][j]=min_cost[i][j-1];
            bagWt[i][j]=bagWt[i][j-1];
          }
        }
      }
    }
  }


}
for(int o =0; o<size; o++){
  for(int l =0; l<50; l++){
   std::cout << bagWt[o][l] << " ";
 }
 std::cout << std::endl;
}
}


std::cout << min_cost[5][49] << std::endl;


for (int i = 0; i < size; i++){
  for (int j = 0; j < 50; j++){
    std::cout << min_cost[i][j] << " ";
  }
  std::cout<<std::endl;
}


}

