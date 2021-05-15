#include "FileCheck.h"

bool checkedHashes = false;

#ifdef DEBUG
void PrintHashes()
{
    std::vector<std::string> resourceFiles = {"achievements.xml", "anaerobic_bomber.txt", "anaerobic_bomber.xml", "anaerobic_cruiser.txt", "anaerobic_cruiser.xml", "anaerobic_cruiser_2.txt", "anaerobic_cruiser_2.xml", "anaerobic_scout.txt", "anaerobic_scout.xml", "animations.xml", "autoBlueprints.xml", "auto_assault.txt", "auto_assault.xml", "auto_basic.txt", "auto_basic.xml", "blueprints.xml", "bosses.xml", "boss_1.txt", "boss_1.xml", "boss_1_easy.txt", "boss_1_easy.xml", "boss_2.txt", "boss_2.xml", "boss_2_easy.txt", "boss_2_easy.xml", "boss_3.txt", "boss_3.xml", "boss_3_easy.txt", "boss_3_easy.xml", "circle_bomber.txt", "circle_bomber.xml", "circle_cruiser.txt", "circle_cruiser.xml", "circle_cruiser_2.txt", "circle_cruiser_2.xml", "circle_cruiser_3.txt", "circle_cruiser_3.xml", "circle_scout.txt", "circle_scout.xml", "credits.txt", "crystal_bomber.txt", "crystal_bomber.xml", "crystal_cruiser.txt", "crystal_cruiser.xml", "crystal_cruiser_2.txt", "crystal_cruiser_2.xml", "crystal_scout.txt", "crystal_scout.xml", "dlcAnimations.xml", "dlcBlueprints.xml", "dlcBlueprintsOverwrite.xml", "dlcEvents.xml", "dlcEventsOverwrite.xml", "dlcEvents_anaerobic.xml", "dlcPirateBlueprints.xml", "dlcSounds.xml", "energy_bomber.txt", "energy_bomber.xml", "energy_bomber_pirate.txt", "energy_bomber_pirate.xml", "energy_cruiser.txt", "energy_cruiser.xml", "energy_cruiser_2.txt", "energy_cruiser_2.xml", "energy_cruiser_3.txt", "energy_cruiser_3.xml", "energy_fighter.txt", "energy_fighter.xml", "energy_fighter_pirate.txt", "energy_fighter_pirate.xml", "events.xml", "events_boss.xml", "events_crystal.xml", "events_engi.xml", "events_fuel.xml", "events_imageList.xml", "events_mantis.xml", "events_nebula.xml", "events_pirate.xml", "events_rebel.xml", "events_rock.xml", "events_ships.xml", "events_slug.xml", "events_zoltan.xml", "fed_bomber.txt", "fed_bomber.xml", "fed_cruiser.txt", "fed_cruiser.xml", "fed_cruiser_2.txt", "fed_cruiser_2.xml", "fed_cruiser_3.txt", "fed_cruiser_3.xml", "fed_scout.txt", "fed_scout.xml", "hyperspace.xml", "jelly_button.txt", "jelly_button.xml", "jelly_button_pirate.txt", "jelly_button_pirate.xml", "jelly_croissant.txt", "jelly_croissant.xml", "jelly_croissant_pirate.txt", "jelly_croissant_pirate.xml", "jelly_cruiser.txt", "jelly_cruiser.xml", "jelly_cruiser_2.txt", "jelly_cruiser_2.xml", "jelly_cruiser_3.txt", "jelly_cruiser_3.xml", "jelly_truffle.txt", "jelly_truffle.xml", "jelly_truffle_pirate.txt", "jelly_truffle_pirate.xml", "kestral.txt", "kestral.xml", "kestral_2.txt", "kestral_2.xml", "kestral_3.txt", "kestral_3.xml", "mantis_bomber.txt", "mantis_bomber.xml", "mantis_bomber_pirate.txt", "mantis_bomber_pirate.xml", "mantis_cruiser.txt", "mantis_cruiser.xml", "mantis_cruiser_2.txt", "mantis_cruiser_2.xml", "mantis_cruiser_3.txt", "mantis_cruiser_3.xml", "mantis_fighter.txt", "mantis_fighter.xml", "mantis_fighter_pirate.txt", "mantis_fighter_pirate.xml", "mantis_scout.txt", "mantis_scout.xml", "mantis_scout_pirate.txt", "mantis_scout_pirate.xml", "nameEvents.xml", "names.xml", "newEvents.xml", "rebel_long.txt", "rebel_long.xml", "rebel_long_pirate.txt", "rebel_long_pirate.xml", "rebel_squat.txt", "rebel_squat.xml", "rebel_squat_pirate.txt", "rebel_squat_pirate.xml", "rock_assault.txt", "rock_assault.xml", "rock_cruiser.txt", "rock_cruiser.xml", "rock_cruiser_2.txt", "rock_cruiser_2.xml", "rock_cruiser_3.txt", "rock_cruiser_3.xml", "rock_fight.txt", "rock_fight.xml", "rock_fight_pirate.txt", "rock_fight_pirate.xml", "rock_scout.txt", "rock_scout.xml", "rock_scout_pirate.txt", "rock_scout_pirate.xml", "rooms.xml", "sector_data.xml", "sounds.xml", "stealth.txt", "stealth.xml", "stealth_2.txt", "stealth_2.xml", "stealth_3.txt", "stealth_3.xml", "text-de.xml", "text-es.xml", "text-fr.xml", "text-it.xml", "text-ja.xml", "text-pl.xml", "text-pt.xml", "text-ru.xml", "text-zh-Hans.xml", "text_achievements.xml", "text_blueprints.xml", "text_events.xml", "text_misc.xml", "text_sectorname.xml", "text_tooltips.xml", "text_tutorial.xml", "tutorial.xml"};

    SHA3 sha3;

    for (auto f : resourceFiles)
    {
        char* s = G_->GetResources()->LoadFile("data/" + f);
        hs_log_file("{\"%s\", \"%s\"},\n", f.c_str(), sha3(s, strlen(s)).c_str());
    }
}
#endif // DEBUG

#ifndef DEBUG
void CheckHashes()
{
    std::map<std::string, std::string> hashKey = {
    {"achievements.xml", "eaba7ca34a1fd3f2fde40a20d61c82e7afe8883397b458d818731bea50faa83c"},
    {"anaerobic_bomber.txt", "2c9b832bc49bb47db2cfe3c62c8f969f10adecaf309f589a3fd20e1eecce8d46"},
    {"anaerobic_bomber.xml", "8b0794ab99a570ebc58890a9deea0be4a48119e25a3085d81214f77402adf074"},
    {"anaerobic_cruiser.txt", "f2b011ee9701ae0162e31ce7b533a966423854495e6e91a00c8951ec284ad389"},
    {"anaerobic_cruiser.xml", "c7674b56a62b442cd50e5c43c592aa2a657658a2210a04e0348154c331223e34"},
    {"anaerobic_cruiser_2.txt", "1dae20a51b1d0d09ed4be0a60a06bb1151e6dba1a8f7389be84ef3c79de332a7"},
    {"anaerobic_cruiser_2.xml", "fdb016cf1f4ed3d7d7eb2b67a62e3ecec9b4f6c8dbf4d09b91da701f843b61ed"},
    {"anaerobic_scout.txt", "59f162af5b91f09a95e8736f0ce51af535eb515d43c2065d9cce6fb2f9d18e08"},
    {"anaerobic_scout.xml", "5d418ef79afb28998649dc14022b193e43ec09127b921fa2e2f53b63a3c04bb5"},
    {"animations.xml", "472f8c0a4869e62d3ae12fa514537df28b749850490e824e9ad2d834258b1533"},
    {"autoBlueprints.xml", "c066e3e16aeb4e8cf60e1ef71cac32d4c3091e3bb134ca606f29d5edef7d077d"},
    {"auto_assault.txt", "2f09518b999100f7b9456a82a4721bd3e816b5a29c094acafc569e816e4d1722"},
    {"auto_assault.xml", "7e5cd885fc82ecd31ccb7be6fa254720d5dd464795bf32c8d4750b54674c6cd1"},
    {"auto_basic.txt", "4957a4ebdc23fd91687a226dc480abcc363f810aaef259e6bbe2ae94eca0708f"},
    {"auto_basic.xml", "40cfd3740fd7c86ecfaf67ab31260cc750f74e554100d033a6a1bce251e9bc53"},
    {"blueprints.xml", "2e1c8bb7cdfe0505dae3c64041ec24b23ee068dd659af4847880125b8c1a60b9"},
    {"bosses.xml", "05e827f38c2ffb62aed2b5bfdb443704d985738fc246c7f93f6935099b4ed46e"},
    {"boss_1.txt", "839e324f0d2b18de00587ca211af4ee9418fbd8a0c40e0497cae1c0e6035a675"},
    {"boss_1.xml", "a0f73edaf6f40f2073e06f88978857f0380366f4540f3efd5fe59e2faf411c27"},
    {"boss_1_easy.txt", "65d56a5f046dae750da20601eaec87242ddd28e5c3f7a2e049dd7aad33c581eb"},
    {"boss_1_easy.xml", "a0f73edaf6f40f2073e06f88978857f0380366f4540f3efd5fe59e2faf411c27"},
    {"boss_2.txt", "cbae722a016474b62038d2eb7d7b4ba62348904fcbbee77de9804166431ca934"},
    {"boss_2.xml", "5d8e7dd3304d8a905fba3c84ae6cf7f2b8bdee3fc6b8cf1eee6a2b463c5359fc"},
    {"boss_2_easy.txt", "1158192eaa7456b48eb239fc45133f42947c6e93cac0babaff0aea03290cef0c"},
    {"boss_2_easy.xml", "5d8e7dd3304d8a905fba3c84ae6cf7f2b8bdee3fc6b8cf1eee6a2b463c5359fc"},
    {"boss_3.txt", "7df5c04767faa034d221490b97f8258840ddd4b2ecd8c91e565f3ad422bf1616"},
    {"boss_3.xml", "7f46b5e9df40490805f9ad5dff87477f2d36657422ba0d0c60d79f713c788f73"},
    {"boss_3_easy.txt", "3ffdef6a93453ae2f4ad6a638f717abe585d36ed35d32218ee8df2154eb9ae0b"},
    {"boss_3_easy.xml", "7f46b5e9df40490805f9ad5dff87477f2d36657422ba0d0c60d79f713c788f73"},
    {"circle_bomber.txt", "61e0d4a1105cd6bee5ba341f129e20cab32e19e854042aaa8c7a925a4bace112"},
    {"circle_bomber.xml", "400aa1854e7a732a6755d1115f332c6d162d3b569cca50d2ac697f73192d14eb"},
    {"circle_cruiser.txt", "731a10e57eb0fc2f4dc2148e1b6bbb6a6be22a72e26e1605da6f6520f9f91437"},
    {"circle_cruiser.xml", "a093595673ce00b779ff2a3aa68ecf1eee76c3f01aa820d8ce6f27e77e171c88"},
    {"circle_cruiser_2.txt", "b590ee729afb105bff2a416ba0d35f3758a0d540d223850b8049c4b40e3b47a0"},
    {"circle_cruiser_2.xml", "97fbcdacafc90573e71982a4694d8e6e4291b9897796d93e6d1abb70cc0738e9"},
    {"circle_cruiser_3.txt", "b470e641ecbb770c517a8ac78b4159a8d3bc2406569dfecf1e45a7b2da37e843"},
    {"circle_cruiser_3.xml", "1dfb708cfa3c4b1c68212501ae34671608f86dda451fa99aa4103107d1e780d3"},
    {"circle_scout.txt", "91bd2b44babb6cf665623c6adcb6cd05d651699ae1aeb98519b7ed701e527343"},
    {"circle_scout.xml", "806a316721a74b49d76c247c05fdc5f964855945c24b860b101c88c7ade6cd00"},
    {"credits.txt", "9eab23fea1986c8d57be222ebe7582d2bbd805dd421ed63cd87ad75f9974493d"},
    {"crystal_bomber.txt", "41a58fcc643f0d6ae7cb4174271726f4b691daed568b4561287d52584266fe55"},
    {"crystal_bomber.xml", "fa6333045671027988adecee6f99aa92eadba15a8447da7e069d7dd3bff0d8fd"},
    {"crystal_cruiser.txt", "71dedc19ba506479b28dce912789530476e1f9f481248c09ee05e3f9c03b36d7"},
    {"crystal_cruiser.xml", "24d4ba3905f8d8aa54a94d18594c342609519d2a43f17b574a82fc11e81771fd"},
    {"crystal_cruiser_2.txt", "fab6f88670ea401cba1cc977a907a4eb92da8edb22912d96dd46e305099239b4"},
    {"crystal_cruiser_2.xml", "93814173581e7e3a0e8f3e985b07b1d2552272fd89606a45f3acd9c82dd23d27"},
    {"crystal_scout.txt", "25806a4063a623c454211a51616d88a03b3804f021327b5059e9a098ec89e2f7"},
    {"crystal_scout.xml", "1723557e879bd6971dfe67eefd9ac150bb7f0ed711bbc44dab4e5bf1c6a5038e"},
    {"dlcAnimations.xml", "e0ae47fde8f443439427b39521d5450d597d6a6199d6e64e08ab7a7127f4e575"},
    {"dlcBlueprints.xml", "26bf63efea2b2ff9e0e51d48a91351a8fba21778d4e5871120e8732326f659da"},
    {"dlcBlueprintsOverwrite.xml", "4095f1a20e5599399aed0266952e09aa790a5f95d683d9cec634deec439b7d6c"},
    {"dlcEvents.xml", "260a8acc51ff7052ffbc4564ab55c199808e07b4158b9c71de4cd585873f5db1"},
    {"dlcEventsOverwrite.xml", "26979273a6595c84be6a1a92fc16e4b19be1fe03ed97f85e1159c4b2f335df3b"},
    {"dlcEvents_anaerobic.xml", "303caf6edc4d9c439d5a13ef95e5bcb895076b8d265a22617b389aae638b1dcd"},
    {"dlcPirateBlueprints.xml", "6c255f1182bbdd54867d054401ac17139e1778235532903538ec22256cb714d2"},
    {"dlcSounds.xml", "9f07c8ab8301e2e5febfffa6c7b2739f5359324c9a78c89c0ead48dbd3838d0b"},
    {"energy_bomber.txt", "01a5fd505d5f3c8d69a232328cdba9c237bf4c2fd6f34da6234ebacc46c29102"},
    {"energy_bomber.xml", "3feae28fa3dab6f00322bc288c8185d6b471afaa68b9e8e926b6693b7eb35b33"},
    {"energy_bomber_pirate.txt", "8955717d68a4f7ad76a052e90793f1f78b66001c48aa3844116e9bf60e9e9bb9"},
    {"energy_bomber_pirate.xml", "72a00f218d267211fa555ce8e3f111d9ea0599d5f533d5089be0d56b32af85b4"},
    {"energy_cruiser.txt", "e57dcb17c2e9b2f83abd39ca4f93f8963023d3977506d94ba4012e4a3c22218e"},
    {"energy_cruiser.xml", "e0ec90c8bbf3ac80f6936fb992f8f96e1adfd7f2c6dbb537f7ec6fb4cc94b074"},
    {"energy_cruiser_2.txt", "84b0755965ca1c08d38747c1efb75321c4309ca5f7e69ffab7444b2c23f7543a"},
    {"energy_cruiser_2.xml", "8803c58d0f5d4360531ea611c2a49dc5eefcd9bf948ac5e5c84e5d524fd9a9b6"},
    {"energy_cruiser_3.txt", "7f4456fa6b393fe081262bf4af6e0e2c3a79ae283017cddb8f8d4d6f610c5602"},
    {"energy_cruiser_3.xml", "e0ec90c8bbf3ac80f6936fb992f8f96e1adfd7f2c6dbb537f7ec6fb4cc94b074"},
    {"energy_fighter.txt", "1dcbff655a9a254d4c4da4f9847ac6ed6dca776fb8461f7cd241eb074cc268d0"},
    {"energy_fighter.xml", "0d6ac9b59b5700260dde35334950d1f555075e61fbdb60376d5a9a95e331f3e2"},
    {"energy_fighter_pirate.txt", "4ca8d047c77266363ca0edb940fcf0f8f734fe90fee979c4aebac6f524acf8f3"},
    {"energy_fighter_pirate.xml", "958339ed8f73189338253aa14e30a1716dd11e989cf7013172acb5803b6bfe85"},
    {"events.xml", "a8d12154d407628851bd02a7a368d94dbc2352dee06e829000c023d1f5a376cc"},
    {"events_boss.xml", "94e6f29a34fa5b2d39b7a3cad2e8d62bee0c96ebd3b3cf6561d19c9fde3aca96"},
    {"events_crystal.xml", "16ed1e967d58333e3179c3998efead695afc8311138eb09b18330cbd54c906b2"},
    {"events_engi.xml", "0a687d9a3c220b0cdcaf8e58da8c0806c3f692d101a594bf6e31b33fdc530b99"},
    {"events_fuel.xml", "c4e7dfce9194e22b8d5dba1514e9333a43fd69d30e1b573417c8d18f4b84a0ab"},
    {"events_imageList.xml", "128bc96ac4606594f0fb3059011ff910fcaf7bcc891a70a46a7d35eaee8e998f"},
    {"events_mantis.xml", "044918b0898ee75ad302802b34b135b09087b6b9c7b0d4818cef9aee002ad9df"},
    {"events_nebula.xml", "02a4c32edb7ddf50f2888517feeece8d51c0054065125e34edb9db4930105e3d"},
    {"events_pirate.xml", "d58e74e88f3ee4dd706e8c262a8a34e878d4fee6ec3ebc05d61e947f4c925d71"},
    {"events_rebel.xml", "43d692fd15367866018d4cd670e9616f4ce2bcfdec5f85f7ac385afd37061294"},
    {"events_rock.xml", "242079924975b9bf63f9a317d0dfe26458fcfab119c10f37c048cb66cd990dca"},
    {"events_ships.xml", "38af940efb98fe5af1ebce89bf2890949ca4f74d0c2eb94a64a314606fee29bf"},
    {"events_slug.xml", "07036f9613d05dabf7af65ba4523ed5187ae79a62840cbb6af61b8b3848c1b67"},
    {"events_zoltan.xml", "ec535d3282148d5b59030f43e347b012e6a8ac9e8bff199153a4b966b5cb55c5"},
    {"fed_bomber.txt", "69f3820a73fe665f08cb8242531b5346c31c9bd575fcfa60a16b0abc649a3cee"},
    {"fed_bomber.xml", "cf6b55d0df83d9ffde5004ed4d9783fd76102d50545b17772e3734df86b4d525"},
    {"fed_cruiser.txt", "79bad19e6fac990e30c46e40cfefd894accaddcd8c3bc7b706f3f7440788b343"},
    {"fed_cruiser.xml", "fbe6a0b443afa3bfcafb389debb77fca875df3a0de4eaf7647d421cfdbd8c980"},
    {"fed_cruiser_2.txt", "9dee1157f248393ad077510a77e69ebe00d7a46da9ceb01e86dd4847cbba8ce2"},
    {"fed_cruiser_2.xml", "3985c8093a4b586589eba9ac71cd8d7fa091de2e389a98cacceee0c1350d6c80"},
    {"fed_cruiser_3.txt", "a44e02303955ed992df72317f8f84e471b6f7bd6453b954b8d58786cfb84022d"},
    {"fed_cruiser_3.xml", "489b6a33e09fa2f78104631de9cbf764f863303dbc415ed131703b26435d6921"},
    {"fed_scout.txt", "78c7c0775bfd0579e300f1139afa0e9c72161c859323264b87e83f04d368b9b9"},
    {"fed_scout.xml", "84316df4c8a63575e1acf1202c0869d9bff7507d86552f9394319f59b38dee28"},
    {"hyperspace.xml", "1c3c3d742fd74c2334aec4f92686b710355209f6a7ca34419881d801ab495519"},
    {"jelly_button.txt", "87dea5ac6e0043df418382dd81c22c034c176503de8896ab14c1795c3b17245d"},
    {"jelly_button.xml", "9ed3e8b2a74046b6c6da29d0b8931c879ec254cd108a6ab69ca897af7e47c637"},
    {"jelly_button_pirate.txt", "d99f537251a0002ce1d58eaa4247489cd2dc50ab35ca43c9bfe8910f480def2f"},
    {"jelly_button_pirate.xml", "09a9f7eec3ec1c08b6becd1466b045332ea57c2c3170b9e61295743b26f41ea9"},
    {"jelly_croissant.txt", "c9b8f0efcaee478b4cd6386ebd8c549a401de042762ee54f0d92865cb41827c1"},
    {"jelly_croissant.xml", "53cc533bbbdf6e7ff107633c38147e40b562a6d1c0a04b126f6f059a74a536ee"},
    {"jelly_croissant_pirate.txt", "cc93b279d91fe848ffb486362832bd764111882bc3139b66f29102681d18dffe"},
    {"jelly_croissant_pirate.xml", "53cc533bbbdf6e7ff107633c38147e40b562a6d1c0a04b126f6f059a74a536ee"},
    {"jelly_cruiser.txt", "1984da7f0a9867229c8982ff57c486bf0c4fabb1f2361315754b2c66afb2b42e"},
    {"jelly_cruiser.xml", "0ad5e671b82ca0b9b98b64b6b06bb243eb84238f4e2c23a2b629fe62c0ca71af"},
    {"jelly_cruiser_2.txt", "d2ff3b0627d2498ebd9163abeafa3c71467ad3bcbdb472dacb7a6842848a37ce"},
    {"jelly_cruiser_2.xml", "a1c6d28ce2103bfae57fe5228259e27bd9c7e023fd28051c1e0b722d25bbafc0"},
    {"jelly_cruiser_3.txt", "aee91283434190f8a305f8a7f689f1ed1905dff0bed6f0323a491e9d38be985b"},
    {"jelly_cruiser_3.xml", "0ad5e671b82ca0b9b98b64b6b06bb243eb84238f4e2c23a2b629fe62c0ca71af"},
    {"jelly_truffle.txt", "14b6fc7a3195220b3992441a38b14d6f469a185b0905f8280df6df78a20f7c44"},
    {"jelly_truffle.xml", "163a2a3c7e0d252d41c39c788f09957cf5daf4037eb06064c0d0df982aa88fc2"},
    {"jelly_truffle_pirate.txt", "a954f0a8af020b6a805c7496ca561b2b1694df0fc1d32cbd29087d4b424df8c0"},
    {"jelly_truffle_pirate.xml", "d0fd797294dca482280eb637018eec2eb0f7140a1f861c491c58d2c7c67284c6"},
    {"kestral.txt", "8b2b1340d39b539ba2a5ffe623c46232e8e7fc5e17457302c5a0b92a5a3175ad"},
    {"kestral.xml", "fc17f887af597afe0dc4dba6e43981d0e6d3fe78a7e0e483b8fc59c84e57595a"},
    {"kestral_2.txt", "3738fbe10e1f7e69d3650a9223bdff81a9cfb98329f2b5906361a6fb69485f8c"},
    {"kestral_2.xml", "431dc9ee8aa5d4f1acf378c65c0cf988fffd52f63401d94ce540b4f6608fe5b0"},
    {"kestral_3.txt", "c4086048948d62ae2e67f94063b292b0f17519543e40b0be20858fc85d80f294"},
    {"kestral_3.xml", "b6b1e7265ad73d5f6ae47cb5d7c5b772f8ff25a088a181528f5818bb53c1ed99"},
    {"mantis_bomber.txt", "058efeea5e64531d078ca2d9a40671d99f321d5234f4987c97ca3784219e0a19"},
    {"mantis_bomber.xml", "5605520a1ed760e97960f1efcc4557675b3b14a06d08b3584a760c62282a96f6"},
    {"mantis_bomber_pirate.txt", "51e595ce03796ce1667437c40468c3984219d0774e2f2ba8842c8935a04ee62f"},
    {"mantis_bomber_pirate.xml", "41cedc25b9db0a62a79d5c8f808dec44f971ac1335ec4429dcacac5c87a9f5cd"},
    {"mantis_cruiser.txt", "5440e2b1447f71b23dc4eae209bb97a127bcf0597877d49cdc94fc51cd5209d5"},
    {"mantis_cruiser.xml", "50a45f3b33d0ee4667700c213873df233d0ee4e0ab0928e63be357562f3a68bc"},
    {"mantis_cruiser_2.txt", "c79e2337376749ec4f2c66097b7238fd76fd44990cab020f94c3f76c9c20dfe2"},
    {"mantis_cruiser_2.xml", "31b8eb38ee435d78dc0582013323989fc01841933934d6e66d6a031db45eabfa"},
    {"mantis_cruiser_3.txt", "75304ebadf0e6b88c1ed61ea368e349ded49561441e6a34fe6187a2e682a76d2"},
    {"mantis_cruiser_3.xml", "5ab7e7a8958e3d4659424b67477197b84e6f35e10c2c1e8b8bf415e84f4e6ae4"},
    {"mantis_fighter.txt", "e1f36449946f686d87f1d6fed480f81797c2cdd0006708bc15dec73e0c8e17c1"},
    {"mantis_fighter.xml", "ecfacdb48015291bc3ac3de69539e15bd73caf377d951d6edfd69345abda16ac"},
    {"mantis_fighter_pirate.txt", "7bb2f8d6e6c41225e11500ba5c798c904c65508b2c5ae4587aaf12874a32d2f9"},
    {"mantis_fighter_pirate.xml", "f86d01deb1457fde5ee450c75865f0425a4f36f5c62f78ef901db8e29fc0af46"},
    {"mantis_scout.txt", "f75a565628f8c2be2c5c28d87a74b5dfae11b04baadfc16222ffa7b916dc1c3e"},
    {"mantis_scout.xml", "43d89322f45b55f9f9df3a9fc47bcf590da79c6cabf65d062552d2b815d72093"},
    {"mantis_scout_pirate.txt", "ee567b2ec4256c0e7ebc18aa13c176ca1867b863dbd78c63f134cd62340ee965"},
    {"mantis_scout_pirate.xml", "5d213b87c75a09349506c9cf580f972633d871d055f37b6f9e7d5e5ccd449ccd"},
    {"nameEvents.xml", "a9950c4f6f4f22fa50c66d24148ee333ca74358bce7297f83fb51a918b6a0903"},
    {"names.xml", "6271608ef10ed2e7aa696e5b699ba79ea9fdee6b3eefd2bde3cf5846f8446bdf"},
    {"newEvents.xml", "84d5b8afcfe55f6d515331fd5266bba7a8276c34b2bf88f7b62baca53b5e04a3"},
    {"rebel_long.txt", "88b246c6a1c8a311700fbf3104cd5e04e377bcf20bd647b85dd33f067f6b87b3"},
    {"rebel_long.xml", "e1e5f6017b505f184c95ef9412b873bea693bf6c8221a439925b246625a63cd1"},
    {"rebel_long_pirate.txt", "4aa3039dd0df00d06e44fa922aeaab3605d4d3b03602cd5475dc8957d80321d1"},
    {"rebel_long_pirate.xml", "8a3c76be4f4471a4e8e2a7400bb91a64931215b20c5e894a86bfc0bec9fb75cb"},
    {"rebel_squat.txt", "61c16c238a8623b51cbf3eef39ccbc79a7dc1901add2a6c8da99266ff929b8ac"},
    {"rebel_squat.xml", "cfa6bc424f7e265cfcf05e1cecab20ecda11a4cd8d017ab45b090b6b88dcb907"},
    {"rebel_squat_pirate.txt", "de048a06b18fc5d88bdce38d1ba1e43b927e2c990ed940f56f5d4348c0b6918e"},
    {"rebel_squat_pirate.xml", "cfa6bc424f7e265cfcf05e1cecab20ecda11a4cd8d017ab45b090b6b88dcb907"},
    {"rock_assault.txt", "392af09d7a897a419e3940c10367e68cbb5914057a2473f35bd0c899686a1a70"},
    {"rock_assault.xml", "1ab688ee25b5da6b334071f47257004952bfc265d255ac9b5798c06eb6c654ad"},
    {"rock_cruiser.txt", "0e3cbf2d3b6ae9c1a96808f71ef9ea3d8891d8054e93016f6eb1732c62addfa7"},
    {"rock_cruiser.xml", "9bd7776830363c3aad9e036b766fc63efa99b69dfbcb41eda087c549f5dc75b8"},
    {"rock_cruiser_2.txt", "5b72938a5bbc0637385d85761e79855bf5c75f2b915a2a476a02c08fa7e409db"},
    {"rock_cruiser_2.xml", "8023ad8a8952eb4706c2b82fd7269bda115bf2883eb014cd4bf8c042ac9464bc"},
    {"rock_cruiser_3.txt", "b40258320d97c191d8a35bd29e7dc79aea4b8611c0e5b996af7e7e5fa9dcaeb5"},
    {"rock_cruiser_3.xml", "9bd7776830363c3aad9e036b766fc63efa99b69dfbcb41eda087c549f5dc75b8"},
    {"rock_fight.txt", "37077d9058d202f4c86dafbe8444251535672f1d5b44db1b13c39f7e9f86022a"},
    {"rock_fight.xml", "be2a06bbc2697c5f348354ea55f6803b5f2b39e1435b5c7cb0b0814d0d40eb95"},
    {"rock_fight_pirate.txt", "cbe2132111a58a171fc4e82a89bd359dccb7eb48c00f470043903868a7b5efbd"},
    {"rock_fight_pirate.xml", "27e16139945df43cfa152c4daf7240be78f3a441e37584c2c74ab0e06b7ef790"},
    {"rock_scout.txt", "6288938de48da9b2decffc9a039e3ff7ab1d4f81f8d86ccec8bbc09a7a0d23f7"},
    {"rock_scout.xml", "85f7b4b3232b6bd93b61a70ff6136bc66a41ed279839d302c87a951e5c0303fb"},
    {"rock_scout_pirate.txt", "6dfccce6e519e9f59bdd766a6fd3963a60ef0f734813aee36eec71c6b5d33e47"},
    {"rock_scout_pirate.xml", "8112ad474953cda2643e54441e98a642fa95b9b393851e7711c64afdcbdfe9f8"},
    {"rooms.xml", "8ae1c30b526fcdd2e50cfc92cd76a4c162346dadd0b89d3535f680d170e42cf8"},
    {"sector_data.xml", "491c034c594cdc2ead401727369e470319b4b0179bcc76bdc38b684a81739a4e"},
    {"sounds.xml", "fff175b4f1036ab5686771597da8c7f6f88ef0f197da5eefefbed885f4245223"},
    {"stealth.txt", "ce67674838f8b7ba5fdc2361c64c9ce3958ce4c4884878df5376cb62cb93d6b3"},
    {"stealth.xml", "91bd60d9c74c1ed5b31abc76cf3a36362dc72c10fc161ed2a18f1c21ed985fbc"},
    {"stealth_2.txt", "d3b26838a2cb6ab5207620b3bea1b22ea4bae591742bfb9cd1b8073f0e3c09f6"},
    {"stealth_2.xml", "6b272db004cebad519417bf9133f3d631d30df67bbcf8bdfc5df5b2a999bfc2a"},
    {"stealth_3.txt", "cda314204a5a78e8daf7c34a904b27ee55133fbc975a98cc53ddf84dc5ce2721"},
    {"stealth_3.xml", "91bd60d9c74c1ed5b31abc76cf3a36362dc72c10fc161ed2a18f1c21ed985fbc"},
    {"text-de.xml", "24dcc902ff3b6de887e3a5dcbb5b284d895c22fd63062eaf9e28ba9e7598cf98"},
    {"text-es.xml", "e390cb61b544a25c3503300b3f365dceab81b30edbc85faead79bc286ef72dc7"},
    {"text-fr.xml", "576153b64065487ec61454f41a0789f0c9e7daebf290e2bf80a2bb7a0fd1cd84"},
    {"text-it.xml", "9bae85cb127bd724a8d348a41cadb2e4aa3a56739cf1c76b534b444e935db568"},
    {"text-ja.xml", "edc5f309b76b11cffd86490eb553a524147dadde1c94f59dc4350a941b10c70e"},
    {"text-pl.xml", "3cfc80cdd3eac5054b63b4f368feef8a3ee4d7f89afe09da99b3da097a431c6e"},
    {"text-pt.xml", "e8a31bffae29b2caf64280acac178b670c250a6f219684d908d4b216deae0763"},
    {"text-ru.xml", "5bf4ad517feef4c10d37ed13f33149ada47c50362fc435be66d670a6a23d22f9"},
    {"text-zh-Hans.xml", "9f4c7fbd97890f0ca9d6ea0d573266048dd0e71ad9a4eb9e7d9ffdb823025514"},
    {"text_achievements.xml", "4b101e106ca740a6b5ed987a58698c8036432f32fbbf1f772cd7c5852e2d611d"},
    {"text_blueprints.xml", "12a84399aae48984bd1de1628b5405d9f1fec50cdb948297cea882f8cf063ad2"},
    {"text_events.xml", "db342ccbf240a0da46bed2b6951bfb370515b6cb1488042c09d38388b98eb9ae"},
    //{"text_misc.xml", "de815d6f65369c0af881781a8562ba83fd12d9bed92788a378485ef91f90b1d3"},
    {"text_sectorname.xml", "bafb17ec4cc2ab7e6f27eea1b678bcd4d5cf20cb6d380be3cd289fc0761f3926"},
    {"text_tooltips.xml", "8c25cbab38e07844044cfa6956218602dd32ff78c4c8b748b8d67ad7060f5ff1"},
    {"text_tutorial.xml", "97110f9c43f00ba497a605dc607e571c99d7c82dd2218f9fad2b40cdcb55d70d"},
    {"tutorial.xml", "8647a79f4bfaa61bca790d7b42b510896a46ca8a30b1a8b76dadb00760afbe73"}
    };

    SHA3 sha3;
    for (auto const& f : hashKey)
    {
        char* s = G_->GetResources()->LoadFile("data/" + f.first);

        std::string sha256 = sha3(s, strlen(s));

        if (sha256 != f.second)
        {
            MessageBoxA(GetDesktopWindow(), "Wrong version of Irie Series Modpack detected. Please check that you are using the correct version of Hyperspace and the modpack.", "Error", MB_ICONERROR | MB_SETFOREGROUND);
            exit(1);
        }
    }
}
#endif // DEBUG

HOOK_METHOD_PRIORITY(AchievementTracker, LoadAchievementDescriptions, 1000, () -> void)
{
    if (!checkedHashes)
    {
        #ifdef DEBUG
        PrintHashes();
        #endif // DEBUG
        #ifndef DEBUG
        CheckHashes();
        #endif // DEBUG
        checkedHashes = true;
    }

    super();
}