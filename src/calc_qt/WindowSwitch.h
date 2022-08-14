#ifndef SRC_CALC_QT_WINDOWSWITCH_H_
#define SRC_CALC_QT_WINDOWSWITCH_H_

template <class A, class B>
void SwitchW(A* ptr) {
  B* window = new B;
  window->show();
  ptr->close();
}

#endif  // SRC_CALC_QT_WINDOWSWITCH_H_
