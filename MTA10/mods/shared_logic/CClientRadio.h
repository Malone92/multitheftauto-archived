/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientRadio.h
*  PURPOSE:     Radio class
*  DEVELOPERS:  Jax <>
*
*****************************************************************************/

#ifndef __CCLIENTRADIO_H
#define __CCLIENTRADIO_H

class CClientManager;

enum eRadioChannel
{
    CHANNEL_POLICE=0,
    CHANNEL_PLAYBACK_FM,
    CHANNEL_K_ROSE,
    CHANNEL_K_DST,
    CHANNEL_BOUNCE_FM,
    CHANNEL_SF_UR,
    CHANNEL_RADIO_LOS_SANTOS,
    CHANNEL_RADIO_X,
    CHANNEL_CSR,
    CHANNEL_K_JAH_WEST,
    CHANNEL_MASTER_SOUNDS,
    CHANNEL_WCTR,
    CHANNEL_USER_TRACK_PLAYER,
    CHANNEL_RADIO_OFF,
};

#define NUM_RADIO_CHANNELS ( CHANNEL_RADIO_OFF + 1 )

class CClientRadio
{
public:
                                CClientRadio        ( CClientManager * pManager );
                                ~CClientRadio       ( void );

    void                        DoPulse             ( void );
    void                        Render              ( void );

    bool                        IsPlaying           ( void );    
    void                        Start               ( void );
    void                        Stop                ( void );

    eRadioChannel               GetFirstChannel     ( void );
    eRadioChannel               GetLastChannel      ( void );

    inline eRadioChannel        GetChannel          ( void )    { return m_Channel; }
    void                        SetChannel          ( eRadioChannel channel );
    bool                        CanChangeChannel    ( void );

    const char *                GetChannelName      ( void );
    const char *                GetChannelName      ( eRadioChannel channel );

    bool                        DoTuneForChannel    ( eRadioChannel channel );    

    void                        NextChannel         ( void );
    void                        PreviousChannel     ( void );

private:
    CClientManager *            m_pManager;
    eRadioChannel               m_Channel;
    eRadioChannel               m_PreviousChannel;
    bool                        m_bPlaying;
    bool                        m_bTuning;
    bool                        m_bTuneForThisChannel;
    unsigned long               m_ulChangeTick;
    bool                        m_bPoliceRadio;

    static char *               m_ChannelNames [ NUM_RADIO_CHANNELS ];
};


#endif