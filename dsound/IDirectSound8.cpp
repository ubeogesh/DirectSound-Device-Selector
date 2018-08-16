/**
* Copyright (C) 2018 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "dsound.h"

HRESULT m_IDirectSound8::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectSound || riid == IID_IDirectSound8 || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectSound8::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectSound8::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		delete this;
	}

	return x;
}

// IDirectSound methods
HRESULT m_IDirectSound8::CreateSoundBuffer(LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER *ppDSBuffer, LPUNKNOWN pUnkOuter)
{
	HRESULT hr = ProxyInterface->CreateSoundBuffer(pcDSBufferDesc, ppDSBuffer, pUnkOuter);

	if (SUCCEEDED(hr))
	{
		*ppDSBuffer = ProxyAddressLookupTable.FindAddress<m_IDirectSoundBuffer8>(*ppDSBuffer);
	}

	return hr;
}

HRESULT m_IDirectSound8::GetCaps(LPDSCAPS pDSCaps)
{
	HRESULT hr = ProxyInterface->GetCaps(pDSCaps);

	return hr;
}

HRESULT m_IDirectSound8::DuplicateSoundBuffer(LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate)
{
	if (pDSBufferOriginal)
	{
		pDSBufferOriginal = static_cast<m_IDirectSoundBuffer8 *>(pDSBufferOriginal)->GetProxyInterface();
	}

	HRESULT hr = ProxyInterface->DuplicateSoundBuffer(pDSBufferOriginal, ppDSBufferDuplicate);

	if (SUCCEEDED(hr))
	{
		*ppDSBufferDuplicate = ProxyAddressLookupTable.FindAddress<m_IDirectSoundBuffer8>(*ppDSBufferDuplicate);
	}

	return hr;
}

HRESULT m_IDirectSound8::SetCooperativeLevel(HWND hwnd, DWORD dwLevel)
{
	return ProxyInterface->SetCooperativeLevel(hwnd, dwLevel);
}

HRESULT m_IDirectSound8::Compact()
{
	return ProxyInterface->Compact();
}

HRESULT m_IDirectSound8::GetSpeakerConfig(LPDWORD pdwSpeakerConfig)
{
	return ProxyInterface->GetSpeakerConfig(pdwSpeakerConfig);
}

HRESULT m_IDirectSound8::SetSpeakerConfig(DWORD dwSpeakerConfig)
{
	return ProxyInterface->SetSpeakerConfig(dwSpeakerConfig);
}

HRESULT m_IDirectSound8::Initialize(LPCGUID pcGuidDevice)
{
	return ProxyInterface->Initialize(pcGuidDevice);
}

// IDirectSound8 methods
HRESULT  m_IDirectSound8::VerifyCertification(LPDWORD pdwCertified)
{
	return ProxyInterface->VerifyCertification(pdwCertified);
}
