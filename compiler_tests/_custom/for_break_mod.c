int f()
{
  int i;
  int y = 30;
  int z = 1;
  for(i = 0; i < 10; i++){
    if(i == 5){
      break;
    }
    y += i;
  }
  y += 1;
  y -= z;
  return y;
}
