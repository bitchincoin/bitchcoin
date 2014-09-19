// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2013-2014 The Dogecoin developers
// Copyright (c)      2014 The Inutoshi developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
  
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc1;
        pchMessageStart[1] = 0xc2;
        pchMessageStart[2] = 0xc4;
        pchMessageStart[3] = 0xc1;
        //owned and valid alert key
        vAlertPubKey = ParseHex("0451BBFA5B928095F41C9FF44DB2ECAD9257C550E720B46AE9AF06F3476D9967E5DBE9907972E6D85608C8A7B36D64BDFDA8900A2A5A67478FCBAB03A58D03A4AE");
        nDefaultPort = 6112; //p2p port
        nRPCPort = 6111;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyHalvingInterval = 210000;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        const char* pszTimestamp = "NY Times 9/17/2014 Obama Pressing Leaders to Speed Ebola Response";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        //use a probably impossible public key
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("000000000000000000000000000000000000000005b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nBits    = 0x1e0ffff0;


genesis.nTime = 1411016405;
genesis.nNonce = 1544266;
        hashGenesisBlock = genesis.GetHash();
assert(genesis.hashMerkleRoot == uint256("0x174e2f91a7f6e3a4596df7f48a4744de494dcfffee00a652274f4049eac4b7c0"));
assert(genesis.GetHash() == uint256("0x00000ebcecd9c5bec0311d97f997d09c887b6952123f1a492d417ed1e3e6282f"));


        if (false) 
        {
            //This will output (to stdout) the code for a new genesis block when it is found
            genesis.nTime=time(NULL);
            genesis.nNonce=0;
            printf("Searching for genesis block...\n");

            uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
            uint256 thash;

            while(1)
            {
                thash=genesis.GetHash();
                if (thash <= hashTarget)
                    break;
                if ((genesis.nNonce & 0xFFFF) == 0)
                {
                    printf("nonce %08X: hash = %s \n",genesis.nNonce, thash.ToString().c_str());
                }
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    printf("NONCE WRAPPED, incrementing time\n");
                    ++genesis.nTime;
                }
            }
            printf("genesis.nTime = %u;\n",genesis.nTime);
            printf("genesis.nNonce = %u;\n",genesis.nNonce);
            printf("assert(genesis.hashMerkleRoot == uint256(\"0x%s\"));\n",genesis.hashMerkleRoot.ToString().c_str());
            printf("assert(genesis.GetHash() == uint256(\"0x%s\"));\n",genesis.GetHash().ToString().c_str());
            exit(1);
        }


        vSeeds.push_back(CDNSSeedData("seed1.bitchcoin.net", "seed1.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed2.bitchcoin.net", "seed2.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed3.bitchcoin.net", "seed3.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed4.bitchcoin.net", "seed4.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed5.bitchcoin.net", "seed5.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed6.bitchcoin.net", "seed6.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed7.bitchcoin.net", "seed7.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed8.bitchcoin.net", "seed8.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed1.fractalco.in", "seed1.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed2.fractalco.in", "seed2.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed3.fractalco.in", "seed3.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed4.fractalco.in", "seed4.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed5.fractalco.in", "seed5.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed6.fractalco.in", "seed6.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed7.fractalco.in", "seed7.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed8.fractalco.in", "seed8.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("earlz.net", "earlz.net"));


        // Workaround for Boost not being quite compatible with C++11;
        std::vector<unsigned char> pka = list_of(36);
        base58Prefixes[PUBKEY_ADDRESS] = pka;
        
        std::vector<unsigned char> sca = list_of(20);
        base58Prefixes[SCRIPT_ADDRESS] = sca;
        //SENDALERT: note, to use sendalert with WIF compressed, change to list_of(128) (here and for testnet as well)
        std::vector<unsigned char> sk  = list_of(125);
        base58Prefixes[SECRET_KEY]     = sk;
        
        std::vector<unsigned char> epk = list_of(0x04)(0x88)(0xC4)(0x2E);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;
        
        std::vector<unsigned char> esk = list_of(0x04)(0x88)(0xE1)(0xF4);
        base58Prefixes[EXT_SECRET_KEY] = esk;

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const uint64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }
    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xfc;
        //owned and valid alert key
        vAlertPubKey = ParseHex("0451BBFA5B928095F41C9FF44DB2ECAD9257C550E720B46AE9AF06F3476D9967E5DBE9907972E6D85608C8A7B36D64BDFDA8900A2A5A67478FCBAB03A58D03A4AE");
        nDefaultPort = 5112;
        nRPCPort = 5111;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start so that they don't match

        genesis.nTime = 1411022846;
genesis.nNonce = 592527;
        hashGenesisBlock = genesis.GetHash();
assert(genesis.hashMerkleRoot == uint256("0x174e2f91a7f6e3a4596df7f48a4744de494dcfffee00a652274f4049eac4b7c0"));
assert(genesis.GetHash() == uint256("0x000003030c996912d1d5d0b47f41ab2316da31cea8e15b5c44226aaf76ab351f"));

        if (false) 
        {
            //This will output (to stdout) the code for a new genesis block when it is found
            genesis.nTime=time(NULL);
            genesis.nNonce=0;
            printf("Searching for genesis block...\n");

            uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
            uint256 thash;

            while(1)
            {
                thash=genesis.GetHash();
                if (thash <= hashTarget)
                    break;
                if ((genesis.nNonce & 0xFFFF) == 0)
                {
                    printf("nonce %08X: hash = %s \n",genesis.nNonce, thash.ToString().c_str());
                }
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    printf("NONCE WRAPPED, incrementing time\n");
                    ++genesis.nTime;
                }
            }
            printf("genesis.nTime = %u;\n",genesis.nTime);
            printf("genesis.nNonce = %u;\n",genesis.nNonce);
            printf("assert(genesis.hashMerkleRoot == uint256(\"0x%s\"));\n",genesis.hashMerkleRoot.ToString().c_str());
            printf("assert(genesis.GetHash() == uint256(\"0x%s\"));\n",genesis.GetHash().ToString().c_str());
            exit(1);
        }

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testnet.bitchcoin.net", "testnet.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("earlz.net", "earlz.net"));
        vSeeds.push_back(CDNSSeedData("seed1.bitchcoin.net", "seed1.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed2.bitchcoin.net", "seed2.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed3.bitchcoin.net", "seed3.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed4.bitchcoin.net", "seed4.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed5.bitchcoin.net", "seed5.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed6.bitchcoin.net", "seed6.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed7.bitchcoin.net", "seed7.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed8.bitchcoin.net", "seed8.bitchcoin.net"));
        vSeeds.push_back(CDNSSeedData("seed1.fractalco.in", "seed1.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed2.fractalco.in", "seed2.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed3.fractalco.in", "seed3.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed4.fractalco.in", "seed4.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed5.fractalco.in", "seed5.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed6.fractalco.in", "seed6.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed7.fractalco.in", "seed7.fractalco.in"));
        vSeeds.push_back(CDNSSeedData("seed8.fractalco.in", "seed8.fractalco.in"));

        // Boost sucks, and should not be used. Workaround for Boost not being compatible with C++11;
        
        std::vector<unsigned char> pka = list_of(138);
        base58Prefixes[PUBKEY_ADDRESS] = pka;
        std::vector<unsigned char> sca = list_of(196);
        base58Prefixes[SCRIPT_ADDRESS] = sca;
        std::vector<unsigned char> sk  = list_of(241);
        base58Prefixes[SECRET_KEY]     = sk;
        std::vector<unsigned char> epk = list_of(0x04)(0x35)(0xD1)(0xDF);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;
        std::vector<unsigned char> esk = list_of(0x04)(0x35)(0x75)(0xA4);
        base58Prefixes[EXT_SECRET_KEY] = esk;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1296688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x3d2160a3b5dc4a9d62e7e66a295f70313ac808440ef7400d6c0772171ce973a5"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
