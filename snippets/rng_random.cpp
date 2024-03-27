mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int mn,int mx)
{
  return uniform_int_distribution<int>(mn,mx)(rng);
}
