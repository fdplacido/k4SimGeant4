#ifndef SIMG4COMPONENTS_G4SINGLEPARTICLEGENERATORTOOL_H
#define SIMG4COMPONENTS_G4SINGLEPARTICLEGENERATORTOOL_H

// Include files
// from Gaudi
#include "GaudiAlg/GaudiTool.h"

#include "SimG4Interface/IG4EventGeneratorTool.h"

// Forward declarations
class G4Event;

/** @class G4SingleParticleGeneratorTool G4SingleParticleGeneratorTool.h "G4SingleParticleGeneratorTool.h"
*
*  Tool that generates single particles with parameters set via options file.
*
*  @author Andrea Dell'Acqua, J. Lingemann
*  @date   2014-10-01
*/

class G4SingleParticleGeneratorTool : public GaudiTool, virtual public IG4EventGeneratorTool {
public:
  /// Standard constructor
  G4SingleParticleGeneratorTool( const std::string& type , const std::string& name,
             const IInterface* parent ) ;

  virtual ~G4SingleParticleGeneratorTool( ); ///< Destructor

  /// Initialize method
  virtual StatusCode initialize( ) ;

  /// Finalize method
  virtual StatusCode finalize( ) ;

  /// Generates primaries using the parameters set via options file, uses CLHEP:RandFlat random number generator
  /// @returns G4Event with primaries generated through G4ParticleGun (ownership is transferred to the caller)
  virtual G4Event* getG4Event() ;

private:
  double m_energyMin;       ///< Minimum energy of the particles generated
  double m_energyMax;       ///< Maximum energy of the particles generated
  double m_etaMin;          ///< Minimum eta of the particles generated
  double m_etaMax;          ///< Maximum eta of the particles generated
  double m_phiMin;          ///< Minimum phi of the particles generated
  double m_phiMax;          ///< Maximum phi of the particles generated
  double m_vertexX;         ///< x position of the vertex associated with the particles generated
  double m_vertexY;         ///< y position of the vertex associated with the particles generated
  double m_vertexZ;         ///< z position of the vertex associated with the particles generated
  std::string m_particleName; ///< Name of the generated particle

};

#endif
