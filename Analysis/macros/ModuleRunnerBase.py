import os
import sys

class GenericPath:
    ''' Class containter for paths '''
    def __init__(self):
        self.user = os.environ["USER"]
        self.cmssw_base = os.environ["CMSSW_BASE"]
        self.isMaxwell = True if "beegfs" in os.getcwd() else False
        self.Path_NFS       = "/nfs/dust/cms/user/"+self.user+"/"
        self.Path_Maxwell   = "/beegfs/desy/user/"+os.environ["USER"]+"/"
        self.Path_ANALYSIS  = self.cmssw_base+"/src/UHH2/VHResonances/"
        self.Path_SFRAME    = self.Path_NFS+"sframe_all/"
        self.Path_STORAGE   = self.Path_NFS+"WorkingArea/File/Analysis/"
        self.Path_SPlotter  = self.Path_NFS+"WorkingArea/SFramePlotter/"
    def Get(self, source):
        return getattr(self,source)



class VariablesBase(GenericPath):
    ''' Class containter for list of objects '''
    def __init__(self):
        GenericPath.__init__(self)
        self.PrefixrootFile     = "uhh2.AnalysisModuleRunner."
        self.Collections        = ["Puppi"]
        self.Channels           = ["muon", "electron", "invisible"]
        self.Systematics        = ["nominal", "JER_up", "JER_down", "JEC_up", "JEC_down", "MuonScale_up", "MuonScale_down"]
        self.Systematics_Scale  = ["PU_up", "PU_down"]
        self.signal             = "MC_ZprimeToZH"
        self.MassPoints         = [600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000]
        self.SignalSamples      = [self.signal+"_"+str(mass) for mass in self.MassPoints]
        self.RunPeriods_Dict    = {"2016": ["B", "C", "D", "E", "F", "G", "H"],
                                   "2017": ["B", "C", "D", "E", "F"],
                                   "2018": ["A", "B", "C", "D"]
                                   }
        self.years              = self.RunPeriods_Dict.keys()
        self.AllRunPeriods      = list(set(itertools.chain.from_iterable(self.RunPeriods_Dict.values())))

        self.SubSamples_Dict    = {# TODO MC_DY_HT70to100
            "MC_DY"                 : ["MC_DY_HT100to200", "MC_DY_HT200to400", "MC_DY_HT400to600", "MC_DY_HT600to800", "MC_DY_HT800to1200", "MC_DY_HT1200to2500", "MC_DY_HT2500toInf", "MC_DY_inv_PtZ_50To100", "MC_DY_inv_PtZ_100To250", "MC_DY_inv_PtZ_250To400", "MC_DY_inv_PtZ_400To650", "MC_DY_inv_PtZ_650ToInf", "MC_DY_inv_HT_100To200", "MC_DY_inv_HT_200To400", "MC_DY_inv_HT_400To600", "MC_DY_inv_HT_600To800", "MC_DY_inv_HT_800To1200", "MC_DY_inv_HT_1200To2500", "MC_DY_inv_HT_2500ToInf"],
            "MC_TTbar"              : ["MC_TTTo2L2Nu", "MC_TTToHadronic", "MC_TTToSemiLeptonic"],
            "MC_WW_incl"            : ["MC_WW"],
            "MC_WZ_incl"            : ["MC_WZ"],
            "MC_ZZ_incl"            : ["MC_ZZ"],
            "MC_WW"                 : ["MC_WWTo4Q", "MC_WWToLNuQQ", "MC_WWTo2L2Nu"],
            "MC_WZ"                 : ["MC_WZToLNu2Q", "MC_WZTo2Q2Nu", "MC_WZTo2L2Q", "MC_WZTo1L3Nu", "MC_WZTo3LNu"],
            "MC_ZZ"                 : ["MC_ZZTo4Q", "MC_ZZTo2Q2Nu", "MC_ZZTo2L2Q", "MC_ZZTo2L2Nu", "MC_ZZTo4L"],
            "DATA_SingleElectron"   : ["DATA_SingleElectron_Run"+str(run) for run in self.AllRunPeriods],
            "DATA_SingleMuon"       : ["DATA_SingleMuon_Run"+str(run) for run in self.AllRunPeriods],
            "DATA_MET"              : ["DATA_MET_Run"+str(run) for run in self.AllRunPeriods],
            self.signal             : self.SignalSamples,
            }

        self.ExtractVariableFromConstants()
        self.defineSamples()

    def ExtractVariableFromConstants(self):
        with open(self.Path_ANALYSIS+"include/constants.hpp") as f_:
            self.lumi_map = {}
            line = f_.readline()
            keeploop = False
            while line:
                while "lumi_map" in line or keeploop:
                    keeploop = True
                    line = f_.readline()
                    if '};' in line:
                        keeploop = False; continue
                    if "201" in line.split()[1] or "RunII" in line.split()[1]:
                        year = str(line.split()[1][1:-2])
                        line = f_.readline()
                        while not "}}," in line:
                            self.lumi_map.setdefault(year,{}).setdefault(str(line.split()[1][1:-2]),str(line.split()[-1][:-2]))
                            line = f_.readline()
                line = f_.readline()

    def defineSamples(self):

        self.Samples_dict = {}
        self.Samples_original = {}
        self.Samples_Category = {}

        for year in self.RunPeriods_Dict:
            for x in self.SubSamples_Dict:
                loop_over = self.SubSamples_Dict[x]
                if (year=="2016" and x=="MC_TTbar"): loop_over = ["MC_TTbar"]
                if (year!="2016" and (x=="MC_WW" or x=="MC_WZ" or x=="MC_ZZ") ): loop_over = self.SubSamples_Dict[x+"_incl"]
                self.Samples_dict.setdefault(year, {}).setdefault(x+"_"+year, [el+"_"+year for el in loop_over] )
            for x in ["DATA_SingleElectron","DATA_SingleMuon", "DATA_MET"]:
                self.Samples_dict[year][x+"_"+year] = [el for el in self.Samples_dict[year][x+"_"+year] if any("Run"+crl in el for crl in self.RunPeriods_Dict[year])]
            self.Samples_original.setdefault(year, list(dict.fromkeys([el for list_ in self.Samples_dict[year].values() for el in list_])))
            self.Samples_Category.setdefault(year, self.Samples_dict[year].keys())
            self.Samples_Category[year].remove(self.signal+"_"+year)
            self.Samples_Category[year].extend(self.Samples_dict[year][self.signal+"_"+year])

        self.Samples_NamesAll = []
        for x in self.Samples_original:
            self.Samples_NamesAll.extend(self.Samples_original[x])

        self.Samples_CategoryAll = []
        for x in self.Samples_Category:
            self.Samples_CategoryAll.extend(self.Samples_Category[x])





class ModuleRunnerBase(VariablesBase):
    ''' Class containter for list of objects for particular year '''
    def __init__(self,year="2016"):
        VariablesBase.__init__(self)
        self.year = year
        self.defineDirectories()
        self.lumi_fb  = round(float(self.lumi_map[year]["lumi_fb"]),1)
        self.lumi_pb  = int(self.lumi_map[self.year]["lumi_pb"])
        self.lumi_sys = round(float(self.lumi_map[year]["uncertainty"]),1)


    def defineDirectories(self):
        self.Path_SFRAME        = self.Path_SFRAME+self.year+"/"
        self.ConfigDir          = self.Path_ANALYSIS+"config/"
        self.SubmitDir          = self.ConfigDir+"SubmittedJobs/"+self.year+"/"
