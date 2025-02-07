////////////////////////////////////////////////////////////////////////////
//
// \brief Definition of OpHit object for LArSoft
//
// \author bjpjones@mit.edu
//         cschiu@mit.edu
//
////////////////////////////////////////////////////////////////////////////
#ifndef OPHIT_H
#define OPHIT_H

#include <limits>

namespace recob {

  /// hits are 2D representations of charge deposited in the tdc/wire plane
  /// hits are assumed to be made from deconvoluted, unipolar signals
  class OpHit {
  public:
    static constexpr double DefaultTime = std::numeric_limits<double>::max();

    OpHit(); // Default constructor

  private:
    int fOpChannel;
    unsigned short fFrame;
    double fPeakTime;
    double fPeakTimeAbs;
    double fStartTime;
    double fRiseTime;
    double fWidth;
    double fArea;
    double fAmplitude;
    double fPE;
    double fFastToTotal;

  public:
    OpHit(int opchannel,
          double peaktime,
          double peaktimeabs,
          double starttime,
          double risetime,
          unsigned short frame,
          double width,
          double area,
          double peakheight,
          double pe,
          double fasttototal);

    OpHit(int opchannel,
          double peaktime,
          double peaktimeabs,
          unsigned short frame,
          double width,
          double area,
          double peakheight,
          double pe,
          double fasttototal);

    // Get Methods
    int OpChannel() const;
    double PeakTimeAbs() const;
    double PeakTime() const;
    double StartTime() const;
    double RiseTime() const;
    unsigned short Frame() const;
    double Width() const;
    double Area() const;
    double Amplitude() const;
    double PE() const;
    double FastToTotal() const;
    friend bool operator<(const OpHit& a, const OpHit& b);

    //Returns true if the StartTime has been initialized
    bool HasStartTime() const;
  };
}

inline int recob::OpHit::OpChannel() const
{
  return fOpChannel;
}
inline unsigned short recob::OpHit::Frame() const
{
  return fFrame;
}
inline double recob::OpHit::PeakTime() const
{
  return fPeakTime;
}
inline double recob::OpHit::PeakTimeAbs() const
{
  return fPeakTimeAbs;
}
inline double recob::OpHit::StartTime() const
{
  return fStartTime;
}
inline double recob::OpHit::RiseTime() const
{
  return fRiseTime;
}
inline double recob::OpHit::Width() const
{
  return fWidth;
}
inline double recob::OpHit::Area() const
{
  return fArea;
}
inline double recob::OpHit::Amplitude() const
{
  return fAmplitude;
}
inline double recob::OpHit::PE() const
{
  return fPE;
}
inline double recob::OpHit::FastToTotal() const
{
  return fFastToTotal;
}
inline bool recob::OpHit::HasStartTime() const
{
  return fStartTime != DefaultTime;
}

#endif
