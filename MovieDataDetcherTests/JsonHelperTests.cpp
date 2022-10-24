﻿#include <gtest/gtest.h>
#include "JsonHelper.h"
#include "MovieNotFoundException.h"
#include "InvalidInputException.h"

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassOnlyOneMovieWithRightName_ReturnThatMovieId)
{
	// Pass Json string with "Avengers: Endgame" movie
	std::string input = "{\"page\":1,\"results\":[{\"adult\":false,\"backdrop_path\":\"/7RyHsO4yDXtBv1zUU3mTpHeQ0d5.jpg\",\"genre_ids\":[12,878,28],\"id\":299534,\"original_language\":\"en\",\"original_title\":\"Avengers: Endgame\",\"overview\":\"After the devastating events of Avengers: Infinity War, the universe is in ruins due to the efforts of the Mad Titan, Thanos. With the help of remaining allies, the Avengers must assemble once more in order to undo Thanos' actions and restore order to the universe once and for all, no matter what consequences may be in store.\",\"popularity\":239.5,\"poster_path\":\"/or06FN3Dka5tukK1e9sl16pB3iy.jpg\",\"release_date\":\"2019-04-24\",\"title\":\"Avengers: Endgame\",\"video\":false,\"vote_average\":8.3,\"vote_count\":21964}],\"total_pages\":1,\"total_results\":1}";
	auto result = JsonHelper::GetMatchingTitleIdFromMovieList("Doctor Strange", input);

	ASSERT_EQ(result, "299534");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassMovieList_ReturnBestMatchingTitleId)
{
	// Pass Json string with movies matching the name "Doctor Strange"
	std::string input = "{\"page\":1,\"results\":[{\"adult\":false,\"backdrop_path\":\"/qUv51IFUvVRAP2379ThmA3eLJx6.jpg\",\"genre_ids\":[28,12,14],\"id\":284052,\"original_language\":\"en\",\"original_title\":\"Doctor Strange\",\"overview\":\"After his career is destroyed, a brilliant but arrogant surgeon gets a new lease on life when a sorcerer takes him under her wing and trains him to defend the world against evil.\",\"popularity\":130.873,\"poster_path\":\"/uGBVj3bEbCoZbDjjl9wTxcygko1.jpg\",\"release_date\":\"2016-10-25\",\"title\":\"Doctor Strange\",\"video\":false,\"vote_average\":7.4,\"vote_count\":19674},{\"adult\":false,\"backdrop_path\":\"/gUNRlH66yNDH3NQblYMIwgZXJ2u.jpg\",\"genre_ids\":[14,28,12],\"id\":453395,\"original_language\":\"en\",\"original_title\":\"Doctor Strange in the Multiverse of Madness\",\"overview\":\"Doctor Strange, with the help of mystical allies both old and new, traverses the mind-bending and dangerous alternate realities of the Multiverse to confront a mysterious new adversary.\",\"popularity\":945.204,\"poster_path\":\"/9Gtg2DzBhmYamXBS1hKAhiwbBKS.jpg\",\"release_date\":\"2022-05-04\",\"title\":\"Doctor Strange in the Multiverse of Madness\",\"video\":false,\"vote_average\":7.5,\"vote_count\":5970},{\"adult\":false,\"backdrop_path\":\"/vy3uI3PCQWVnoW7OrKzB65Ba02c.jpg\",\"genre_ids\":[28,16,14,878],\"id\":14830,\"original_language\":\"en\",\"original_title\":\"Doctor Strange\",\"overview\":\"Dr. Stephen Strange embarks on a wondrous journey to the heights of a Tibetan mountain, where he seeks healing at the feet of the mysterious Ancient One.\",\"popularity\":19.52,\"poster_path\":\"/er6ZENdFks9SzodFHZ5IBuhb9iR.jpg\",\"release_date\":\"2007-08-14\",\"title\":\"Doctor Strange\",\"video\":false,\"vote_average\":6.9,\"vote_count\":273},{\"adult\":false,\"backdrop_path\":\"/sgrqnoVFNgP90C3jdtxNGJPyVK3.jpg\",\"genre_ids\":[99],\"id\":448383,\"original_language\":\"en\",\"original_title\":\"Doctor Strange: The Score-Cerer Supreme\",\"overview\":\"A discussion of Michael Giacchino's work on the film and the themes the music conveys and supports for the film.\",\"popularity\":17.561,\"poster_path\":\"/zHJYRHI5HkQuwLW5KyeXGQ596u7.jpg\",\"release_date\":\"2017-02-28\",\"title\":\"Doctor Strange: The Score-Cerer Supreme\",\"video\":true,\"vote_average\":8.3,\"vote_count\":10},{\"adult\":false,\"backdrop_path\":null,\"genre_ids\":[99],\"id\":448387,\"original_language\":\"en\",\"original_title\":\"Doctor Strange: The Fabric of Reality\",\"overview\":\"A detailed examination of the film's costumes: construction, functionality, and staying true to the characters. It also covers set design and construction, shooting in key locations, the film's scope, filming locations, and more.\",\"popularity\":10.972,\"poster_path\":\"/hdtlZ8ScjcEiYiIb5OqTnrz7CG8.jpg\",\"release_date\":\"2017-02-28\",\"title\":\"Doctor Strange: The Fabric of Reality\",\"video\":true,\"vote_average\":9.5,\"vote_count\":2},{\"adult\":false,\"backdrop_path\":\"/coxMHDtNRcyNmriZFCxpwqmlxjS.jpg\",\"genre_ids\":[99],\"id\":980017,\"original_language\":\"en\",\"original_title\":\"ASSEMBLED: The Making of Doctor Strange in the Multiverse of Madness\",\"overview\":\"Join visionary director Sam Raimi and the cast of the film as they recount their experiences bringing Marvel’s darkest story to life.  From world-building to universe-building, hear first hand accounts from the cast and crew on what it took to design, create and make each universe unique and believable.\",\"popularity\":10.558,\"poster_path\":\"/eIzPe62s12uHsIPhGWY1yp68DY9.jpg\",\"release_date\":\"2022-07-08\",\"title\":\"ASSEMBLED: The Making of Doctor Strange in the Multiverse of Madness\",\"video\":false,\"vote_average\":6.4,\"vote_count\":15},{\"adult\":false,\"backdrop_path\":null,\"genre_ids\":[99],\"id\":1017831,\"original_language\":\"en\",\"original_title\":\"Marvel & DC's War on God: Doctor Strange, Aleister Crowley and the Multiverse of Satanism\",\"overview\":\"Doctor Strange, Aleister Crowley and the Multiverse of Satanism is part 2 in a 7-part series exposing how the popular Marvel character, Doctor Strange, has its origins based on the most notorious satanist of all time, Aleister Crowley.\",\"popularity\":5.032,\"poster_path\":\"/1krmUGxtLS7P9amRbzXAzBlS22E.jpg\",\"release_date\":\"2022-09-02\",\"title\":\"Marvel & DC's War on God: Doctor Strange, Aleister Crowley and the Multiverse of Satanism\",\"video\":false,\"vote_average\":10,\"vote_count\":1},{\"adult\":false,\"backdrop_path\":\"/fBaWg3pMbiOLlZkLc0nGOuDXePV.jpg\",\"genre_ids\":[18,36],\"id\":881927,\"original_language\":\"zh\",\"original_title\":\"The Strange Doctor Tang Shenwei\",\"overview\":\"\",\"popularity\":0.6,\"poster_path\":\"/5L5qpvhy76pOD0BQpourJV45UlM.jpg\",\"release_date\":\"2014-01-01\",\"title\":\"The Strange Doctor Tang Shenwei\",\"video\":false,\"vote_average\":2,\"vote_count\":1},{\"adult\":false,\"backdrop_path\":null,\"genre_ids\":[99],\"id\":809046,\"original_language\":\"pt\",\"original_title\":\"Doutor Estranho Amor - ou como aprendi a amar o preservativo e deixei de me preocupar\",\"overview\":\"This documentary shows a Brigade of medicine students that goes to a school to prevent AIDS. For 10 weeks, we follow their failures and achievements with a class of difficult but interesting characters. A film that asks us many questions about talking of sexuality and that is an important case study to the actual political debate on sexual education.  The Brigades are voluntary groups of medicine students, who go to the schools to prevent risky behaviours and fight AIDS.  Doctor Strange Love follows the action of a Brigade in the midst of a teenager class, focusing on value contrasts and relationships, through this experience of changing minds and consciousness.\",\"popularity\":0.883,\"poster_path\":null,\"release_date\":\"2005-01-01\",\"title\":\"Doctor Strange Love\",\"video\":false,\"vote_average\":2,\"vote_count\":1},{\"adult\":false,\"backdrop_path\":\"/kw4GhCZP5NeMVsfPol6HcX9JEeQ.jpg\",\"genre_ids\":[10770,28,12,14,878],\"id\":50468,\"original_language\":\"en\",\"original_title\":\"Dr. Strange\",\"overview\":\"A psychiatrist becomes the new Sorcerer Supreme of the Earth in order to battle an evil Sorceress from the past.\",\"popularity\":14.611,\"poster_path\":\"/hEyHVgBE28Jl13h2Qpbr3LH77sP.jpg\",\"release_date\":\"1978-09-06\",\"title\":\"Dr. Strange\",\"video\":false,\"vote_average\":6.3,\"vote_count\":77}],\"total_pages\":1,\"total_results\":10}";
	auto result = JsonHelper::GetMatchingTitleIdFromMovieList("Doctor Strange", input);

	ASSERT_EQ(result, "284052");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassEmptyJsonString_ThrowInvalidInputException)
{
	std::string input = "";

	ASSERT_THROW(JsonHelper::GetMatchingTitleIdFromMovieList("Doctor Strange", input), InvalidInputException);
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassEmptyList_ThrowMovieNotFoundException)
{
	std::string input = "{\"page\":1,\"results\":[],\"total_results\":0,\"total_pages\":1}";

	ASSERT_THROW(JsonHelper::GetMatchingTitleIdFromMovieList("Doctor Strange", input), MovieNotFoundException);
}
