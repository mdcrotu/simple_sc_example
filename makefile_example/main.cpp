#include <systemc.h>

SC_MODULE (dummy_module) {
  sc_event e1;
  sc_event e2;
  sc_event e3;

  SC_CTOR (dummy_module) {
      SC_THREAD(thread_with_wait);
      sensitive << e1;
      dont_initialize();

      SC_THREAD(thread_without_wait);
      sensitive << e2;
      dont_initialize();

      SC_METHOD(method_without_wait);
      sensitive << e3;
      dont_initialize();
  }

  void thread_with_wait(){
      while(1){
          cout << "In thread_with_wait" << endl;
          wait();
      }
      return;
  }

  void thread_without_wait(){
      cout << "In thread_without_wait" << endl;
      return;
  }

  void method_without_wait(){
      cout << "In method_without_wait" << endl;
      return;
  }
};

int sc_main(int argc, char* argv[]) {
  dummy_module dummy("DUMMY");
  sc_clock CLK("CLK", 10, SC_NS, 0.5, 0.0, SC_NS, false);

  //Try SC_THREAD with wait multiple times
  sc_start(10, SC_NS);
  dummy.e1.notify();
  sc_start(10, SC_NS);

  sc_start(10, SC_NS);
  dummy.e1.notify();
  sc_start(10, SC_NS);

  //Try SC_THREAD without wait multiple times
  sc_start(10, SC_NS);
  dummy.e2.notify();
  sc_start(10, SC_NS);

  sc_start(10, SC_NS);
  dummy.e2.notify();
  sc_start(10, SC_NS);

  //Try SC_METHOD without wait multiple times
  sc_start(10, SC_NS);
  dummy.e3.notify();
  sc_start(10, SC_NS);

  sc_start(10, SC_NS);
  dummy.e3.notify();
  sc_start(10, SC_NS);

  return 0;
}
