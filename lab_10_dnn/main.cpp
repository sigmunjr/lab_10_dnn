#include "Dnn_lab.h"

int main()
{
  try
  {
    Dnn_lab lab{"../../data"};
    lab.run();
  }
  catch (cv::Exception e)
  {
    std::cerr << e.msg << "\n";
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() <<"\n";
  }
  catch (...)
  {
    std::cerr << "Unknown exception caught in main()\n";
  }

  return 0;
}
