bool cmp2 ( string a , string b )
{
    for ( int i = 0 ; i < min ( a.length() , b.length()) ; i++ )
        if ( a[i] != b[i] ) return 1 ;

}
bool cmp ( string a , string b )
{
    if ( cmp2(a,b) ) return a < b ;
    return a.length() < b.length() ;
}


        for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
                string str ="";
                 for ( int j = 0; j < n ; ++ j ) {
                     if ( ( i & ( 1 << j ) ) != 0 )
                           str.pb(s[j]);
                     }
                   if ( str == string(str.rbegin(),str.rend())) res.push_back(str);
                 }