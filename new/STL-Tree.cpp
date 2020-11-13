#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//find_by_order() returns an iterator to the k-th largest element (counting from zero)
//order_of_key() returns the number of items in a set that are strictly smaller than our item
// use lower_bound or upper_bound for erase 
// less for set less_equal for multiset, ps: lower_bound works as upper_bound and vice-versa.