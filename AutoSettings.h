#ifndef AutoSettings_h
#define AutoSettings_h

class AutoSettings {
public:
  enum AutoMode { TIME, LIGHT };

  AutoSettings();
  void setAutoMode(AutoMode mode);
  void setAutoEnabled(bool enabled);
  void setAutoTimes(int upHour, int upMinute, int downHour, int downMinute);

private:
  AutoMode mode_;
  bool enabled_;
  int _upHour, _upMinute, _downHour, _downMinute;
};

#endif


//nynynnynnnyynynny
