int mn = inf ;
  for  (int msk = 1 ; msk < 1<<n ; msk++ ){
    ANS[msk] = ANS[msk - (msk&-msk)]| Mask[idx[(msk&-msk)]] ;
   if ( ANS[msk] == (1<<n)-1 )
    mn = min (__builtin_popcount(msk) , mn ) ;
  }