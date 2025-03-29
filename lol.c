if ((a=b) && (a=c)){
    printf("equilateral triangle");
    }
  else if ((a=b && a != c) || (a=c && a!=b) || (b=c && c != a))
    {
    printf("isoceles triangle");
    }
  else if (a+b>c || a+c>b || b+c>a)
  {
    printf("scalene triangle");
  }
  else
  {
    printf("triangle not possible");
  }
  }

